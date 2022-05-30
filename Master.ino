/*
SIT217 Software Engineering Robotics Project
Task 7.2D
File Master.ino(Transmiter)
Name : Sohil Nagpal 
Student ID : 2110994793
*/

#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

int m1a = 3;
int m1b = 4;
int m2a = 5;
int m2b = 6;
char val;

RF24 radio(7, 8);

const byte address[] = "rover";

void setup()
{
  pinMode(m1a, OUTPUT); 
  pinMode(m1b, OUTPUT); 
  pinMode(m2a, OUTPUT); 
  pinMode(m2b, OUTPUT); 
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
}

void loop()
{
  while (Serial.available() > 0)
  {
    val = Serial.read();
    Serial.println(val);
  }

  if (val == 'F') // Forward
  {
    forward();
    radio.write(&val, sizeof(val));
  }
  else if (val == 'B') // Backward
  {
    backward();
    radio.write(&val, sizeof(val));
  }

  else if (val == 'L') // Left
  {
    left();
    radio.write(&val, sizeof(val));
  }
  else if (val == 'R') // Right
  {
    right();
    radio.write(&val, sizeof(val));
  }
  else if (val == 'S') // Stop
  {
    stop();
    radio.write(&val, sizeof(val));
  }
}

void forward()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void backward()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
}

void right()
{
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

void left()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
}

void stop()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}
