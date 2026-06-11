#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long mypow(long long x, long long y) {
	long long tot = 1LL;
	while (y) {
		if (y & 1) tot = (tot * x) % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return tot;
}

long long ans[100005];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	
	for (int i = k; i >= 1; i--) {
		int x = k / i;
		long long cur = mypow(x, n);
		for (int j = 2; j <= k / i; j++) {
			cur = (cur - ans[j * i] + MOD) % MOD;
		}
		ans[i] = cur;
	}
	
	long long res = 0;
	
	for (int i = 1; i <= k; i++) res = (res + 1LL * i * ans[i]) % MOD;
	
	printf("%lld\n", res);
}
