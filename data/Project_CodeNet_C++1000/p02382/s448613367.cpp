#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	double x[101], y[101];
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &x[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &y[i]);
	}
	double D, total=0;
	int p;
	p = 1;
	for (i = 0; i < n; i++)
	{
		total += powl(abs(x[i] - y[i]), p);
	}
	D = total;
	printf("%lf\n", D);
	p = 2, total = 0;
	for (i = 0; i < n; i++)
	{
		total += powl(abs(x[i] - y[i]), p);
	}
	D = sqrtl(1.0*total);
	printf("%lf\n", D);
	p = 3, total = 0;
	for (i = 0; i < n; i++)
	{
		total += powl(abs(x[i] - y[i]), p);
	}
	D = cbrtl(1.0*total);
	printf("%lf\n", D);
	float pp;
	pp = INFINITY, total = 0;
	for (i = 0; i < n; i++)
	{
		if (1.0*abs(x[i] - y[i]) > total)
		{
			total = 1.0*abs(x[i] - y[i]);
		}
	}
	D = total;
	printf("%lf\n", D);
	return 0;
}