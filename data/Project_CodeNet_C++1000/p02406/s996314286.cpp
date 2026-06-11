#include<stdio.h>
int main()
{
int a,b,c;
int i;
scanf("%d",&a);
for(i=1;i<=a;i++)
{
b=i%10;
c=i/10;
if(i%3==0)
{
printf(" %d",i);
}
else if(b==3)
{
printf(" %d",i);
}
else if(c==3)
{
printf(" %d",i);
}
else if(c%10==3)
{
printf(" %d",i);
}
else if(c/10==3)
{
printf(" %d",i);
}
else if(c/10%10==3)
{
printf(" %d",i);
}
else if(c/10/10==3)
{
printf(" %d",i);
}
}
printf("\n");
return 0;
}