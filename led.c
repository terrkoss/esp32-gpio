#include <stdio.h>
#include "sdkconfig.h"

int *GPIO_ENABLE_REG = (int *) 0x3FF44020;
int *GPIO_OUT_REG =(int *) 0x3FF44004; /*led*/
int *GPIO_IN_REG = (int *) 0x3FF4403C; /*button*/




void app_main(void)
{
    *GPIO_ENABLE_REG |= (1U << 22); 
    *GPIO_ENABLE_REG |= (1U << 21);

    while (1)
    {
    
        int read_pin = (*GPIO_IN_REG >> 23) &  1U ;
        if(read_pin) 
        {
            
             
            *GPIO_OUT_REG |= (1U << 22);
            *GPIO_OUT_REG |= (1U << 21);
            
            
        }
        else if (read_pin == 0)
        {
                 
             *GPIO_OUT_REG &= ~(1 << 21);
             
             if (read_pin == 1)
             {

                *GPIO_OUT_REG |= ~(1U << 22);
                
                
             }
             


             
           
        }
        
       
        
    }
   
    
}