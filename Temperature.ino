#include <stdio.h>

const int LM35_PIN = A0;
const int LED_PIN = 13;

unsigned long previousMillis = 0;
int blinkInterval = 250; // Initial interval for LED blink

void setup() {
  printf("Serial communication initialized at 9600 baud.\n");
  
  // LED pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Temperature from LM35 Sensor
  int sensorValue = analogRead(LM35_PIN);
  float temperature = sensorValue * 0.48875; // Convert sensor value to temperature in degrees Celsius
  
  // Temperature value from the sensor
  printf("Temperature: %.2f\n", temperature);
  
  // Control LED based on temperature
  if (temperature < 30) {
    blinkInterval = 250;
  } else {
    blinkInterval = 500;
  }
  
  // Blink LED
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis;
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
