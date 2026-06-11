#include<stdio.h>

int main()
{
	int a;
	long long total =0;
	int sum =0;
	int z =0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		if(i%3!=0&&i%5!=0)
		{
			total +=i;
	    }
	}
	printf("%lld",total);
	return 0;
}