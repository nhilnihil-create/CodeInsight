#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   static long i,j,k,l;
   long n;
   long cnt = 0;
   long left,right,mid;
   long ans = 0;
   int a,b;
   static int H[10000];
   static int W[10000];


   for(i = 0;; i++) {
      scanf("%d %d",&H[i],&W[i]);
      if(H[i] == 0)
         break;
   }
   for(j = 0; j < i; j++) {
      for(l = 0; l < W[j]; l++)
         putchar('#');
         putchar('\n');
      for(k = 1; k < H[j]-1; k++) {
         putchar('#');
         for(l = 1; l < W[j]-1; l++) {
            putchar('.');
         }
         putchar('#');
         putchar('\n');
      }
      for(l = 0; l < W[j]; l++)
         putchar('#');
      putchar('\n');
      putchar('\n');
   }

   return 0;
}