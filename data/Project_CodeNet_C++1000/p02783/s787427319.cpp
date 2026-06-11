#include<stdio.h>

int main()
{
 int a,b,temp;
 scanf("%d %d",&a,&b);
 while(a>0){
  a=a-b;
  temp++;
 }
 printf("%d\n",temp);
 
return 0;
}