#include<stdio.h>
int main()
{
	long long int sum=0;
	int n,a;
	int max=-1000000,min=1000000;
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		if(a>max)  max=a;
		if(a<min)  min=a;
		sum+=a;
	}	
	printf("%d %d %lld\n",min,max,sum);
	return 0;
}