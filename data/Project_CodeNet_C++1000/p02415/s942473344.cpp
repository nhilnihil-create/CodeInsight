#include <stdio.h>
 
int main(void){
  int i=0;
  char str[1200];
 
  gets(str);
 
  while(1)
    {
      if(str[i] == '\0')
        {
          break;
        }
      if('a' <= str[i] && str[i] <= 'z')
        {
          str[i] -= 0x20;
        }
      else if('A' <= str[i] && str[i] <= 'Z')
        {
          str[i] += 0x20;
        }
      i++;
    }
 
  puts(str);
  return 0;
}