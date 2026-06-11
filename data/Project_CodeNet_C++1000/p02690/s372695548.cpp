#include <iostream>
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int x;
  long a,b;
  int max_roop = 130;
  bool roop_break = false;
  int i,j;
  
  scanf("%d",&x);
  
  for(a = -max_roop; a <=max_roop; a++)
  {
    for(b = -max_roop; b <=max_roop; b++)
    {
      if((a*a*a*a*a - b*b*b*b*b) == x)
      {
        printf("%d %d\n",a,b);
        roop_break = true;
        break;
      }
    }
    
    if(roop_break)
    {
      break; 
    }
  }
  
  return 0;
}