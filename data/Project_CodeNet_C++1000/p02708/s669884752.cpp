#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	ll n, k; cin >> n >> k;
	ll min_sum[200005];
	ll max_sum[200005];
	ll now = 0;
	// i個選んだときの和の最小値
	for(ll i=1;i<=n+1;i++){
		now += i-1;
		min_sum[i] = now;
	}
	// i個選んだときの和の最大値
	for(ll i=n+1;i>=1;i--){
		max_sum[i] = now;
		now -= n-i+1;
	}
	ll ans = 0;
	for(ll i=k;i<=n+1;i++){
		ans += (max_sum[i]-min_sum[i]+1)%MOD;
	}
	cout << ans%MOD << endl;
	return 0;
}