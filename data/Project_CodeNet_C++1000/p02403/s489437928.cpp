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
printf("#");
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