#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
const ll MOD = 1e9 + 7;

int mainsolve(){

	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	vector<P> ps(n);
	rep(i,n) ps[i] = P(a[i],i);
	sort(ps.rbegin(), ps.rend());

	ll INF = 1e18;
	vector<vector<ll>> dp(n+1,vector<ll>(n+1, -INF));
	rep(i,n+1) dp[0][i] = 0;

	rep(i,n){
		rep(j,n+1){
          	if(i < j) continue;
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + ps[i].first * (n-(i-j)-1 - ps[i].second));
			if(j+1 <= n) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + ps[i].first * (ps[i].second - j));
		}
	}

	ll res = 0;
	rep(i,n+1) res = max(res, dp[n][i]);
	cout << res << endl;
	return 0;
}

int main(){

	return mainsolve();
}