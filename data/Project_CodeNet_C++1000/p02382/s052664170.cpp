#include<stdio.h>
#include<math.h>

int main()
{
	int x[100], y[100],n;
	double p;
/*?°???\??¨???*/
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &y[i]);
	}
/*??????????????????????????¢*/
	for (p = 1; p < 4; p++)
	{
		double minkohu = 0;
		for (int a=0; a < n; a++)
		{
			minkohu = minkohu + pow(fabs(x[a] - y[a]), p);
		}
		minkohu = pow(minkohu, 1 / p);
		printf("%lf\n", minkohu);
		minkohu = 0;
	}
/*?????§????????§????????¢*/
	double distance,num;
	distance = fabs(x[0] - y[0]);
	for (int j = 1; j < n; j++)
	{
		num = fabs(x[j] - y[j]);
		if (num > distance)
		{
			distance = num;
		}
	}
	printf("%lf\n", distance);
	return 0;
}