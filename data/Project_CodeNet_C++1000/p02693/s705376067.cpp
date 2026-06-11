#include<stdio.h>

int main()
{
	int k, a, b, i;
	int count = 0;
	scanf("%d", &k);
	scanf("%d %d", &a, &b);
	
	for (i = a; i <= b; i++)
	{
		if (i % k == 0)
		{
			count++;
		}
	}
	
	if (count > 0)
	{
		printf("OK\n");
	}
	
	else
	{
		printf("NG\n");
	}
	
	return 0;
}