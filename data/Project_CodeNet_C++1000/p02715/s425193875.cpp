#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100 * 1000 + 4;
const ll MOD = 1e9 + 7;
ll dp[MAXN];
ll n, k;

ll pw(ll a, ll b){
	if( b == (ll)0)
		return (ll)1;
	a %= MOD;
	if( b % 2 )
		return (pw(a * a, b/2) % MOD * a) % MOD;
	else
		return pw(a * a, b/2) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for( ll kp = k; kp >= 1; kp --){
		ll g = pw(k/kp, n) % MOD;
		ll p = 0;
		for( int j = 2 * kp; j <= k; j += kp)
			p = (p + dp[j]) % MOD;
		dp[kp] = (g - p + MOD) % MOD;
//		cout << dp[kp] << endl;
	}
	ll ans = 0;
	for( int i = 1; i <= k; i ++){
		ans = (ans + (dp[i] % MOD * i % MOD)) % MOD;
		ans %= MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}
