#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

int main(){
	ll mod = 1e9 + 7;
	ll n, k; cin >> n >> k;
	ll arr[n];
	for(ll i = 0; i < n; ++i){
		cin >> arr[i];
	}
	ll ans = 0;
	for(ll i = 0; i < n; ++i){
		ll cnt = 0;
		for(ll j = i + 1; j < n; ++j){
			if(arr[i] > arr[j]){
				cnt++;
			}
		}
		ll tmp = k;
		ans += ((cnt * ((tmp * (tmp + 1) / 2)  % mod)) % mod);
		ans %= mod;
		cnt = 0;
		for(ll j = 0; j < i; ++j){
			if(arr[i] > arr[j]){
				cnt++;
			}
		}
		tmp = k - 1;
		ans += ((cnt * ((tmp * (tmp + 1) / 2)  % mod)) % mod);
		ans %= mod;
	}
	cout << ans;
    return 0;
}
