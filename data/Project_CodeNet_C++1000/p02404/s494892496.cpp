#include<stdio.h>
int main()
{
int H,W;
int i,j;
int h,w;
for(;;)
{
 scanf("%d %d",&H,&W);
 h=H-2;
 w=W-2;
 if(H!=0&&W!=0)
 { 
  for(i=1;i<=H;i++)
  {
   if(i==1||i==H)
   {
    for(j=1;j<=W;j++)
    {
     printf("#");
    }
    printf("\n");
   }
   else if(i!=1&&i!=H)
   {
    printf("#");
    for(j=1;j<=w;j++)
    {
     printf(".");
    }
    printf("#\n");
   }
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
   