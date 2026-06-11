
#include <stdio.h>

#define MAX 600

int function(int d)
{
	d = d * d;
	return d;
}

int main()
{
	int d,cnt;
	int sum;
	while ((scanf("%d", &d)) != EOF)
	{
		sum = 0;
		cnt = MAX / d;
		for (int i = 1; i < cnt; i++)
		{
			sum += function(d*i)*d;
		}
		printf("%d\n",sum);
	}
	return 0;
}