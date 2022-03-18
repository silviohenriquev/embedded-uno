#include <Arduino.h>
#include "ports.h"
#include <LoRaE220Communication.h>

LoRaE220Communication lora(e220_TX, e220_RX, e220_AUX, e220_M0, e220_M1, DeviceFunction::sensor);   

SensorData sensorData;

void setup(){
	Serial.begin(9600);
    delay(100);
	
 	lora.setup();
    lora.printParameters();

    sensorData.id = 1;
    sensorData.tempCell = 37.1;
    sensorData.tempExternal = 34.7;
    sensorData.tempInternal = 32.2;
    sensorData.irradiance = 750;
    sensorData.date = 1647555749;
}

void loop(){
	lora.sendSensorsDataPacket(sensorData);
    delay(1000);
}

