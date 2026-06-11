#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
   int n,a,b,c;
   scanf("%d %d %d", &a, &b, &c);
   scanf("%d", &n);
   while(b<=a && n!=0)
   {
       b*=2;
       n--;
   }
   while(c<=b && n!=0)
   {
       c*=2;
       n--;
   }
   if(a<b && b<c) printf("Yes");
   else printf("No");
}
