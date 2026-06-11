#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define SQR(X) ( (X) * (X) )

int main()
{
   long i,j,k,l;
   long n;
   long double s;
   long double sum,nizyou;
   static long double dev[1000];

   for(i=0;;i++) {
      cin >> n;
      if(n==0)
         break;
      sum=0;
      nizyou=0;
      for(j=0;j<n;j++) {
         cin >> s;
         sum += s;
         nizyou += s*s;
      }
      dev[i] = sqrtl(nizyou/n - SQR(sum/n));
   }


   for(j=0;j<i;j++)
      printf("%llf\n",dev[j]);

   return 0;
}