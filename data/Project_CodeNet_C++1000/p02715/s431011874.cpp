#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

int add (int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul (ll a, ll b) {
	a *= b;
	if (a >= mod) a %= mod;
	return a;
}

int sub (int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int binpow (int a, int b) {
	int res = 1;
	while (b) {
		if ((b&1)) res = mul(res, a);
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k, ans = 0;
	cin >> n >> k;
	vector <int> dp(k+1);
	for (int i=k; i>=1; i--) {
		int cnt = k/i;
		dp[i] = binpow(cnt, n);
		for (int j=2; j*i<=k; j++) {
			dp[i] = sub(dp[i], dp[i*j]);
		}
	}
	for (int i=1; i<=k; i++) {
		ans = add(ans, mul(i, dp[i]));
	}
	cout << ans;
	return 0;
}
