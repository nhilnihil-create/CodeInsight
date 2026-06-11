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
   long double x1,x2,y1,y2;
   long double ans;
   cin >> x1 >> y1 >> x2 >> y2;
   ans = sqrtl(SQR(x1-x2)+SQR(y1-y2));
   printf("%llf\n",ans);

   return 0;
}