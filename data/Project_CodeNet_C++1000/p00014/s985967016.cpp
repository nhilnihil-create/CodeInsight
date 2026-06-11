#include<stdio.h>

int main()
{
	int d, i;
	while (scanf("%d", &d) != EOF)
	{
		if (d == 0)break;
		long int total = 0;
		for (i = d; i < 600; i += d)
		{
			total = total + i*i*d;
		}
		printf("%ld\n", total);
	}
	return 0;
}