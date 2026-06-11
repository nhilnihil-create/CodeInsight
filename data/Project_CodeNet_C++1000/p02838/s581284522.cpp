#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
	int n; scanf("%d", &n);
	vector<ll> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	ll ans = 0;
	for(ll bit = 0; bit <= 60; bit++){
		ll c0 = 0, c1 = 0;
		for(int i = 0; i < n; i++){
			if((a[i] >> bit) & 1) c1++;
			else c0++;
		}
		(ans += ((c0*c1)%MOD) * ((1LL << bit)%MOD)) %= MOD;
	}
	printf("%lld\n", ans);
}