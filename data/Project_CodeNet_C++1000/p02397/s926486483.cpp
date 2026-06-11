#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   long i,j,k;
   long n;
   long cnt = 0;
   long left,right,mid;
   long ans = 0;
   static long x[10000];
   static long y[10000];

   for(i = 0;;i++) {
      scanf("%ld %ld",&x[i],&y[i]);
      if(x[i] == 0 && y [i] == 0)
         break;
      else if(x[i] > y[i]) {
         long tmp = y[i];
         y[i] = x[i];
         x[i] = tmp;
      }

   }
   for(j = 0; j < i; j++) {
      printf("%ld %ld\n",x[j],y[j]);
   }

   return 0;
}