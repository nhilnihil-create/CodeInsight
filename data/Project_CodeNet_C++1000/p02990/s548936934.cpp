#include <cstdio>

#define MOD 1000000007

typedef long long ll;

ll comb[2222][2222];

int main(void)
{
	ll n, k, i, j;

	scanf("%lld %lld" ,&n, &k);

	for (i = 0; i <= n; i++)
	{
		comb[i][0] = 1;
		for (j = 1; j <= i; j++)
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
	}

	for (i = 1; i <= k; i++)
		printf("%lld\n" ,comb[k - 1][i - 1] * comb[n - k + 1][i] % MOD);
	return 0;
}