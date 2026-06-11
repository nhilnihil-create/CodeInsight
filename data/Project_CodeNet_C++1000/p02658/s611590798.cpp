#include<stdio.h>

int main()
{
long long int p[10000000];
long long int b,i,k=0;
long long int m=1000000000000000000;
unsigned long long mul=1;  

scanf("%lld",&b);

for(i=0;i<b;i++)
{
scanf("%lld\n",&p[i]);

}

for(i=0;i<b;i++)
{
if(p[i]==0)
{
k=1;
break;
}
if(mul<=m/p[i])
{
mul=mul*p[i];
}
else
k=2;
}
if(k==1)
{
printf("0\n");
}
else if(k==2)
{
printf("-1\n");
}
else if(k==0)
printf("%llu\n",mul);

return 0;
} 

