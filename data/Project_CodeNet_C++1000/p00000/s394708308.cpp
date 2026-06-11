#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
   int i,j,k,l;
   int a,b,c,d;
   int memory[2];
   int n;

   for(i=1;i<=9;i++) {
      for(j=1;j<=9;j++) printf("%dx%d=%d\n",i,j,i*j);
   }
   return 0;
}