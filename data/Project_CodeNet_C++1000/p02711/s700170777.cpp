#include<stdio.h>

int main()
{
    int n, r, temp, count=0;
    scanf("%d", &n);

   temp = n;
   while(temp>0)
   {
       r = temp%10;
       if(r==7)
        count=1;
       temp = temp/10;
   }
   if(count==1)
   printf("Yes\n");
   else
   printf("No\n");


    return 0;
}
