#include<stdio.h>
int main()
{
   int a,b,c,d,n=0;
   scanf("%d%d",&a,&b);
   for(c=1;c<=b;c++)
   {
       scanf("%d",&d);
       n=n+d;
   }
   if(n>=a)
   {
       printf("Yes");

   }

   else{printf("No");}
    return 0;

}
