#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll ans = 0;
	for(ll digit = 0; digit <= 60; digit++){
		ll c0 = 0, c1 = 0;
		for(int i = 0; i < n; i++){
			if(1LL & (a[i] >> digit)) c1++;
			else c0++;
		}
		ans += (((c0 * c1)%MOD) * ((1ll << digit)%MOD));
		ans %= MOD;
	}
	cout << ans << endl;
}
