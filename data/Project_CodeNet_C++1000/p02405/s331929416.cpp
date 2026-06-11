#include<stdio.h>
int main()
{
int H,W;
int i,j;
for(;;)
{
 scanf("%d %d",&H,&W);
 if(H!=0&&W!=0)
 {
  for(i=1;i<=H;i++)
  {
   for(j=1;j<=W;j++)
   {
    if(i%2==1&&j%2==1||i%2==0&&j%2==0)
    {
     printf("#");
    }
    else if(i%2==1&&j%2==0||i%2==0&&j%2==1)
    {
     printf(".");
    }
   }
   printf("\n");
  }
  printf("\n");
 }
 else
 {
  break;
 }
}
return 0;
}