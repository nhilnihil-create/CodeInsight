#include<stdio.h>
int main() {

	long long int n;
	long long int a[100];
	long long int i;
	long long int j = 0;
	long long int money = 1000;
	scanf("%lld",&n);
	for (i = 0;i < n;i++)
	{
		scanf("%lld", &a[i]);
	}
	
	for (i = 0;i < n;i++)
	{
		if (i == n - 1)
		{
			money += j * a[i];
			j = 0;
		}
		else if (j == 0) {
			if (a[i] >= a[i + 1])
				continue;
			else
			{
				j = money / a[i];
				money %= a[i];
			}
		}
		else
		{
			if (a[i] <= a[i + 1])
			{
				continue;
			}
			else
			{
				money += j * a[i];
				j = 0;
			}
		}

	}
	printf("%lld", money);



	return 0;
}