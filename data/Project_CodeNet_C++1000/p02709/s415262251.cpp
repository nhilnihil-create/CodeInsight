#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[2001][2001];
inline void chmax(ll& a, ll b) {
	a = max(a,b);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	dp[0][0] = 0;
	vector<P> p;
	rep(i,n) p.emplace_back(a[i],i);
	sort(p.rbegin(), p.rend());
	rep(i,n) {
		int pi = p[i].second;
		rep(l,i+1) {
			int r = i-l;
			chmax(dp[i+1][l+1], dp[i][l]+ll(pi-l)*a[pi]);
			chmax(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]);
		}
	}
	ll ans = 0;
	rep(i,n+1) chmax(ans, dp[n][i]);
	cout << ans << endl;

	return 0;
}
