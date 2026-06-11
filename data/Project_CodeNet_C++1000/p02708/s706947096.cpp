#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1e9+7;

int main(){
	ll n , k;
	cin >> n >> k;

	vector<ll> pre(n+3 , 0);

	for(ll i = 0 ; i <= n ; i++){
		pre[i+1] = i + pre[i];
	}

	ll ans = 0;
	for (ll i = k ; i <= (n+1) ; i++){
		ll mx = pre[n+1] - pre[n+1-i];
		ll mn = pre[i];

		ans += ((mx - mn + 1)%mod);
		ans %= mod;
	}

	cout << ans%mod << endl;
	
	return 0;
}
