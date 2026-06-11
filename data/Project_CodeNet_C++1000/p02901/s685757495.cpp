#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
typedef double db;
#define inf 0x3f3f3f3f
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll dp[1 << 13 + 10];
ll _2n[20];
ll n, m;
ll val[1123];
ll a[1123];
signed main() {
	cin >> n >> m;
	ll w, b, i, j, t;
	_2n[0] = 1;
	for (i = 1; i < 15; ++i)_2n[i] = _2n[i - 1] << 1;
	ll tt = 1 << 13 + 5;
	for (i = 0; i < tt; ++i)dp[i] = inf;
	for (i = 0; i < m; ++i) {
		cin >> w >> b;
		val[i] = w;
		for (j = 0; j < b; ++j) {
			cin >> t;
			a[i] += _2n[t-1];
		}
	}
	dp[0] = 0;
	for (i = 0; i < _2n[n]; ++i) {
		for (j = 0; j < m; ++j) {
			dp[i | a[j]] = min(dp[i] + val[j], dp[i | a[j]]);
		}
	}
	if (dp[_2n[n] - 1] >= inf)cout << -1 << endl;
	else cout << dp[_2n[n] - 1] << endl;
	return 0;
}