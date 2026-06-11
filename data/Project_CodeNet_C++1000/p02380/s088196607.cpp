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
   static long i,j,k,l;
   long double a,b,c,C;
   long double ans;
   cin >> a >> b >> C;

   C = C / 180 * 3.14159265;
   c = sqrtl(a*a+b*b-2*a*b*cosl(C));

   printf("%llf\n",a*b*sinl(C)/2);
   printf("%llf\n",a+b+c);
   printf("%llf\n",b*sinl(C));
   return 0;
}