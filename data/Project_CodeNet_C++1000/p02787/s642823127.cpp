#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll h, n, ans = 0;
	cin >> h >> n;
	vector <ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	vector<ll> dp(h + 1);
	rep(i,h + 1) dp[i] = ((i + a[0] - 1) / a[0]) * b[0];
	for (int i = 1; i < n; i++) {
		vector<ll> c(h + 1);
		swap(dp,c);
		rep(j,h + 1) {
			//　使わないか　全部使うか
			dp[j] = min(((j + a[i] - 1) / a[i]) * b[i], c[j]);

			if (j >= a[i]) dp[j] = min(dp[j], dp[j - a[i]] + b[i]);
		}
	}
	ans = dp[h];
	cout << ans << endl;
	return 0;
}
