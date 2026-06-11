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
      for(k = 0; k < H[j]/2; k++) {
         for(l = 0; l < W[j]/2; l++) 
            printf("#.");
         if(W[j] % 2)
            putchar('#');
         puts("");
         for(l = 0; l < W[j]/2; l++) 
            printf(".#");
         if(W[j] % 2)
            putchar('.');
         puts("");
      }
      if(H[j] % 2) {
         for(l = 0; l < W[j]/2; l++) 
            printf("#.");
         if(W[j] % 2)
            putchar('#');
         puts("");
      }
      puts("");
   }


   return 0;
}