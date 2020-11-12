/*
* Stephon Patton
* Assignment 5
* SER486 - Embedded C Programming
 */

#include "delay.h"
#include "led.h"
#include "rtc.h"
#include "timer1.h"
#include "uart.h"

//Forward declaration

int main(void) {
        /* Initializes the led device */
        led_init();

        /* Initializes the uart */
        uart_init();

        /* Initializes the rtc and timer1 */
        rtc_init();

        /* Sets the blink pattern to OK in morse code */
        led_set_blink("--- -.-");

        /* Sets the RTC date/time to January 1, 2019 */
        rtc_set_by_datestr("01/01/2019 00:00:00");

        /* Writes project information to uart */
        uart_writestr("SER486 Project 1 - Stephon Patton\n\r");

        /* get baseline performance */
        signed long c1=0;
        delay_set(1,10000); while (!delay_isdone(1)) { c1++; }

        /* measure performance with led_update */
        signed long c2=0;
        delay_set(1,10000); while (!delay_isdone(1)) { led_update(); c2++; }

        /* display the results */
        uart_writedec32(c1); uart_writestr(" ");
        uart_writedec32(c2); uart_writestr("\r\n");

        while(1) {

        }
}
