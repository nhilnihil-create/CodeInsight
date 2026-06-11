#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
#define MAXK 100002

int N, K;
LL ans = 0;
LL g[MAXK] = {0};

LL fastPow (LL a, LL k) {
	if (a == 0) return 0;

	LL res = 1;
	LL base = a % MOD;
	while (k) {
		if (k & 1) {
			res = res * base % MOD;
		}
		base = base * base % MOD;
		k >>= 1;
	}
	return res % MOD;
}

int main () {
	cin >> N >> K;

	for (int i = K; i >= 1; i --) {
		g[i] = fastPow (K / i, N);
		for (int j = i * 2; j <= K; j += i) {
			g[i] = (g[i] - g[j] + MOD) % MOD;
		}
		ans = (ans + (g[i] * i) % MOD) % MOD;
	}

	cout << ans;
	return 0;
}