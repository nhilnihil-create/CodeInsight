#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
const ll MOD = 1e9 + 7;
const int MX = 1e5 + 5;

string s;

ll mpow(ll a, ll b) {
	a %= MOD;
	b %= (MOD - 1);
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> s;
	ll l = sz(s) - 1;
	ll ans = mpow(3, l);
		
	// Len, (0 -> same, 1 -> below L)
	ll dp[MX][2];
	
	dp[0][0] = 2; dp[0][1] = 0;
	for (int i = 1; i <= l; ++i) {
		if (s[i] == '1') {
			if (dp[i - 1][1]) {
				dp[i][1] = dp[i - 1][1] * 3 % MOD;
				dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
			} else dp[i][1] = dp[i - 1][0];
			
			dp[i][0] = dp[i - 1][0] * 2 % MOD;
		} else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] * 3 % MOD;
		}
	}
	
	cout << ((ans + dp[l][0]) % MOD + dp[l][1]) % MOD;
}	
