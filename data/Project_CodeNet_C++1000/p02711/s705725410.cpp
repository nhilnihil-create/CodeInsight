#include<stdio.h>

int main()

{
   int a;

   scanf("%d",&a);

   if((a/100==7)||(a/10)%10==7||(a%10)==7)
   {
      printf("Yes\n");
   }

   else
   {
      printf("No\n");
   }
}
