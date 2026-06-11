#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	vector<pll> v(n);
	rep(i, n){
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end(), greater<pll>());

	ll dp[n+1][n+1];
	rep(i, n+1) rep(j, n+1) dp[i][j] = 0;

	rep(x, n) rep(y, n){
		int idx = x + y;
		if(idx >= n) continue;

		ll val = v[idx].first;
		ll p = v[idx].second;
		if(p >= x) chmax(dp[x+1][y], dp[x][y] + val * (p - x));
		if(n-1-y >= p) chmax(dp[x][y+1], dp[x][y] + val *(n - 1 - y - p));
	}

	ll ans = 0;
	rep(i, n + 1) chmax(ans, dp[i][n-i]);
	cout << ans << endl;
}
