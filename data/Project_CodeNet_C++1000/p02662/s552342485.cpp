#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 998244353

using namespace std;
using ll = long long;

int main() {
	ll n, s, ans = 0;
	cin >> n >> s;
	vector<int> a(n + 1);
	rep(i,n) cin >> a[i];
	vector<int> dp(s + 1);
	dp[0] = 1; // ０個目までの部分集合で、和が0になるように選べる個数

	rep(i,n) {
		vector<int> bef(s + 1);
		swap(dp, bef);
		rep(k, s + 1) {
			dp[k] += ((bef[k] % MOD) * 2) % MOD;
			if (k + a[i] <= s) dp[k + a[i]] += bef[k] % MOD;
		}
	}
	ans = dp[s] % MOD;
	cout << ans << endl;
	return 0;
}
