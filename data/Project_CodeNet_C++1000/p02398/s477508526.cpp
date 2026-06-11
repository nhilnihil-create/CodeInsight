#include<stdio.h>

main()
{
int a,b,c;
int i,div=0;

scanf("%d %d %d",&a,&b,&c);

for(i=a;i<=b;i++)
 {
 if((c/i*i)==c)div++;
 }

printf("%d\n",div);
}