#include<stdio.h>

int main()
{
	long long int max,sum = 0;
	scanf("%lld", &max);
	for(int i = 0; i <= max; i++)
	{
		if(i % 3 != 0 && i % 5 != 0)
		{
			sum = sum + i;
		}
	}
	printf("%lld", sum);
return 0;
}