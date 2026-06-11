#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define SQR(X) ( (X) * (X) )

long double minkosu(long sa[],long n,long double p)
{
   long i,j;
   long double tmp=0;
   if(p == 100) {
      for(i=0;i<n;i++) {
         if(tmp< fabsl( sa[i] ) )
            tmp = fabsl(sa[i]);
      }
      return tmp;
   }

   else {
      for(i=0;i<n;i++)
         tmp += powl( fabsl( sa[i] ) ,p);


      return powl(tmp,1/p);
   }
}


int main()
{
   long i,j,k,l;
   long n;
   long x[100];
   long y[100];
   long sa[100];

   cin >> n;

   for(i=0;i<n;i++)
      cin >> x[i];

   for(i=0;i<n;i++) {
      cin >> y[i];
      sa[i] = x[i] - y[i];
   }

   printf("%llf\n",minkosu(sa,n,1));
   printf("%llf\n",minkosu(sa,n,2));
   printf("%llf\n",minkosu(sa,n,3));
   printf("%llf\n",minkosu(sa,n,100));

   return 0;
}