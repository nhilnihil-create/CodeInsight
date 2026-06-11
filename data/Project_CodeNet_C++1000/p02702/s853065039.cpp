#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	string s; cin >> s;
	ll n = ll(s.size());
	ll dp[2][2019];
	ll ans = 0;
	rep(i, 0, n){
		rep(j, 0, 2019) dp[1][j] = 0;
		rep(j, 0, 2019) dp[1][(j*10+s[i]-'0')%2019] += dp[0][j];
		dp[1][s[i]-'0']++;
		ans += dp[1][0];
		swap(dp[0], dp[1]);
	}
	cout << ans << endl;
	return 0;
}