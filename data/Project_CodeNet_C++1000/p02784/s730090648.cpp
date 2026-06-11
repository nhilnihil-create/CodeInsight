#include<stdio.h>

int main()
{

   int i;

   long long int H,N,sum=0,arr[100000];

   scanf("%lld %lld",&H,&N);

   for(i=0;i<N;i++)
   {

     scanf("%lld",&arr[i]);

     sum = sum + arr[i];

   }

   if(sum>=H)
   {
     printf("Yes\n");
   }

   else if(sum<H)
   {
     printf("No\n");
   }


   return 0;
}
