#include <stdio.h>

main()
{
int x[3];
int i,j,temp;

scanf("%d %d %d",&x[0], &x[1], &x[2]);

for(i=0;i<3;i++)
 {
 for(j=2;j>i;j--)
  {
   if(x[j-1]>x[j])
    {
     temp=x[j-1];x[j-1]=x[j];x[j]=temp;
    }
  }
 }

printf("%d %d %d\n",x[0],x[1],x[2]);
}