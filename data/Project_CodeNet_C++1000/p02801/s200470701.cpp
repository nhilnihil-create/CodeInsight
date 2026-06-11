#include <stdio.h>

int main()
{
   char character;
   do
   {
       scanf("%c", &character);
   } while (character == 122);

   printf("%c", character + 1);
   

    return 0;
}