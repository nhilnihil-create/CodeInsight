#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return (long long) a * b % MOD;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int fastpow(int x, int y) {
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y /= 2;
	}
	return ret;
}

int sld[MAXN];
vector<int> divi[MAXN];

int main() {
	int n, k; scanf("%d%d", &n, &k);

	int ans = 0;
	for (int d = 1; d <= k; d++)
		for (int j = d; j <= k; j += d)
			divi[j].push_back(d);

	for (int d = k; d >= 1; d--) {
		int cur = fastpow(k/d, n);
		cur = sub(cur, sld[d]);
		ans = add(ans, mul(cur, d));

		for (int p : divi[d])
			sld[p] = add(sld[p], cur);
	}

	printf("%d\n", ans);
}