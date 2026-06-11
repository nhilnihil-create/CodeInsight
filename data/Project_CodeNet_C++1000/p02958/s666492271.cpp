#include<stdio.h>

int main()

{
   int i,j,tc,a[100000],cnt=0,z;

   scanf("%d",&tc);

   for(i=0;i<tc;i++)
   {
      scanf("%d",&a[i]);
   }

   for(j=1,z=0;j<=tc;j++,z++)
   {
      if(j!=a[z])
      {
         cnt++;
      }
   }

   if(cnt<=2)
   {
      printf("YES\n");
   }

   else
   {
      printf("NO\n");
   }
}
