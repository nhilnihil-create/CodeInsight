// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const int mod = 1e9+7;

long long fast_pw(long long x, long long y) {
	long long ret = 1;

	for(;y;y>>=1) {
		if(y & 1) ret = (ret * x) % mod;
		x = (x * x) % mod;
	}
	return ret;
}

long long dp[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	for(int i = k; i >= 1; i--) {
		dp[i] = fast_pw(k / i, n);
		for(int j = i + i; j <= k; j += i) {
			dp[i] = (dp[i] - dp[j] + mod) % mod;
		}
	}

	long long ans = 0;

	for(int i = 1; i <= k; i++) {
		ans += i * dp[i];
		ans %= mod;
	}

	cout << ans;
		

	return 0;
}
