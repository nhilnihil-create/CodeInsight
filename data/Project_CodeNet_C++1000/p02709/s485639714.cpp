// ABC163E.cpp :

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <numeric> // accumulate
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using P = pair<ll, ll>;

int main()
{
	ll n;
	cin >> n;
	vector<P>a(n);
	rep(i, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.rbegin(), a.rend()); // 降順ソート
	vector<vector<ll>>h(2020, vector<ll>(2020));
	// h[x][y] 左からxの場所にy番目の幼児を移動させた時に増えるうれしさ
	rep(i, n) {
		rep(j, n) {
			h[i][j] = a[j].first * max(a[j].second - i, i - a[j].second);
		}
	}
	vector<vector<ll>>dp(2020, vector<ll>(2020)); // dp[左の人数][右の人数]
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + h[i - 1][i - 1];
	}
	for (int j = 1; j <= n; j++) {
		dp[0][j] = dp[0][j - 1] + h[n - j][j - 1];
	}
	ll fromU = 0;
	ll fromR = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fromU = dp[i - 1][j] + h[i - 1][i + j - 1];
			fromR = dp[i][j - 1] + h[n - j][i + j - 1];
			dp[i][j] = max(fromU, fromR);
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			if (i + j == n) {
				ans = max(ans, dp[i][j]);
			}
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	cout << ans << endl;
}