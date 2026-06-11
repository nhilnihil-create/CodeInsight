#include <stdio.h>
int main()
{
int i;
scanf("%d",&i);
long long int sum=0;

for (int a=1;a<=i;a++)
{
	if((a%3==0) ||  (a%5==0))
	{
    }
    else
    {
		sum=sum+a;	    
	}
}
printf("%lld",sum);
	return 0;
}
