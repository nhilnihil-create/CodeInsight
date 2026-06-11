#include<stdio.h>
#include<math.h>

int main()
{
	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		int i, score[1001];
		for (i = 0; i < n; i++)
		{
			scanf("%d", &score[i]);
		}
		int alltotal = 0;
		for (i = 0; i < n; i++)
		{
			alltotal += score[i];
		}
		double avrage = 1.0*alltotal / n;
		double bload[1001];
		for (i = 0; i < n; i++)
		{
			bload[i] = powl(score[i] - avrage, 2);
		}
		double allbload = 0.0;
		for (i = 0; i < n; i++)
		{
			allbload += bload[i];
		}
		double bunsan = allbload / n;
		printf("%lf\n", sqrt(bunsan));

	}
	return 0;
}