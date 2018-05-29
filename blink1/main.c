#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

void delay(uint32_t nCount)
{
      while (nCount--)
      {
      }
}

int main(void)
{
    RCC_DeInit();

    // Enable peripheral clocks
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Configure PC13 pin as output
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    gpio.GPIO_Pin = GPIO_Pin_13;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP; // output push-pull
    GPIO_Init(GPIOC, &gpio);

    while(1)
    {
        // Turn LED on
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay(0x011111);

        // Turn LED off
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay(0x111111);
    }
}
