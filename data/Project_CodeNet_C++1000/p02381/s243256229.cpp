#include<stdio.h>
#include<math.h>

int main(void)
{
	long long int n, s[1000];
	double sum, ans;
	while (1)
	{
		sum = 0;
		ans = 0;
		scanf("%lli", &n);
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			scanf("%lli", &s[i]);
			sum = sum + s[i];
		}
		for (int j = 0; j < n; j++)
		{
			ans = ans + (s[j] - sum / n)*(s[j] - sum / n);
			s[j] = 0;
		}
		printf("%f\n", sqrt(ans / n));
	}
	return 0;
}