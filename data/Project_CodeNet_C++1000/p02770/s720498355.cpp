#include <cstdio>
#include <algorithm>

int main()
{
	int k, q;
	int d[5000];
	scanf("%d%d", &k, &q);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", d + i);
	}
	while (q--)
	{
		long long n, x, m;
		scanf("%lld%lld%lld", &n, &x, &m);
		long long last = x;
		long long eq = 0;
		for (int i = 0; i < k; ++i)
		{
			long long cnt = (n - 1 - i + k - 1) / k;
			last += (long long)d[i] % m * cnt;
			if (d[i] % m == 0) eq += cnt;
		}
		long long ans = (n - 1) - (last / m - x / m) - eq;
		printf("%lld\n", ans);
	}
	return 0;
}
