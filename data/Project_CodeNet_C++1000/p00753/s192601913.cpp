#include<bits/stdc++.h>

using namespace std;

#define int long long

bool isPrime[300000];
int sum[300000];

signed main()
{
	fill_n(isPrime, 300000, true);
	isPrime[0] = isPrime[1] = false;
	int s = sqrt(300000);
	for (int i = 2; i < s; i++)
	{
		if (!isPrime[i]) continue;
		for (int j = 2; i * j < 300000; j++)
		{
			isPrime[i * j] = false;
		}
	}
	
	for (int i = 1; i < 300000; i++)
	{
		sum[i] = sum[i - 1] + isPrime[i];
	}

	int N;
	while (cin >> N, N)
	{
		printf("%lld\n", sum[2 * N] - sum[N]);
	}
	return 0;
}