#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int inv2 = 499122177;

int a[3010];
int dp[3010], f[3010];

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main () {
	int n, S; scanf("%d%d", &n, &S);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	dp[0] = power(2, n);
	for (int i = 0; i < n; i++) {
		for (int j = S; j >= a[i]; j--) {
			dp[j] = (dp[j] + 1ll * dp[j - a[i]] * inv2) % mod;
		}
	}
	printf("%d\n", dp[S]);
	return 0;
}
