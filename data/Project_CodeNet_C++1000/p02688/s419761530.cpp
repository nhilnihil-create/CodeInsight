		#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

using ll = long long;
using ld = long double;

const ll inf = LONG_LONG_MAX;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1){
            res = (res * a)%mod;
        }
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

signed main(){
	ll t;
	//	cin >> t;
	 t = 1;
	while(t--){
		ll n,k;
		cin >> n;

		vector<bool>v(n+1);
		cin >> k;

		for(ll i=0;i<k;i++){
			ll x;
			cin >> x;

			for(ll i=0;i<x;i++){
				ll y;
				cin >> y;
				v[y] = 1;
			}
		}

		ll cnt = 0;
		for(ll i=1;i<=n;i++){
			if(!v[i]){
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}