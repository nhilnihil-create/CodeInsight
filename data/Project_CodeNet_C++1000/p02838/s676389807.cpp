#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, C[60];

int main()
{
	scanf ("%d", &N);
	for (int i = 0; i < N; i++){
		long long x; scanf ("%lld", &x);
		for (int k = 0; k < 60; k++) if (x & (1ll << k)) C[k]++;
	}

	const long long mod = 1000000007;
	long long ans = 0;
	for (int k = 59; k >= 0; k--){
		ans = ans * 2 % mod;
		long long c = 1ll * C[k] * (N - C[k]) % mod;
		ans = (ans + c) % mod;
	}
	printf ("%lld\n", ans);
	return 0;
}