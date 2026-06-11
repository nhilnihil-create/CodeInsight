#include<stdio.h>

int main()
{
	int t;
	long long int a, max=1e18,flag=0,zero=0,prod=1;
	
	scanf("%d",&t);
	
	for (int i=0;i<t;i++)
	{
		scanf("%lld",&a);
		flag=(a>max) ? 1:flag;
		prod*=a;
		a!=0 ? max=max/a : zero=1;
	}
	if (zero==1)
	{
		printf("0\n");
	}
	
	else if (flag == 1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n",prod);
	}
	
	return 0;
}