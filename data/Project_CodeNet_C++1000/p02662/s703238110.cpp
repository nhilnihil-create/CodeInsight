#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

const ll MOD = 998244353;

ll mypow(ll a, ll b){
	if(b == 0) return 1;
	if(b % 2 == 1) return a * mypow(a, b - 1) % MOD;

	ll d = mypow(a, b / 2) % MOD;
	return d * d % MOD;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, s;
	cin >> n >> s;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll dp[n+1][s+1];
	rep(i, n+1) rep(j, s+1) dp[i][j] = 0;
	dp[0][0] = mypow(2, n);
	ll inv2 = mypow(2, MOD - 2);

	rep(i, n){
		rep(j, s+1){
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= MOD;
			
			if(j + a[i] <= s) {
				dp[i+1][j+a[i]] += dp[i][j] * inv2 % MOD;
				dp[i+1][j+a[i]] %= MOD;
			}
		}
	}
	
	cout << dp[n][s] << endl;

}
