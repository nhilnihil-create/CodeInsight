#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
   int n;
   scanf("%d", &n);
   if   (n>=400 && n<=599) printf("8");
   else if(n>=600 && n<=799) printf("7");
   else if(n>=800 && n<=999) printf("6");
   else if(n>=1000 && n<=1199) printf("5");
   else if(n>=1200 && n<=1399) printf("4");
   else if(n>=1400 && n<=1599) printf("3");
   else if(n>=1600 && n<=1799) printf("2");
   else if(n>=1800 && n<=1999) printf("1");
}
