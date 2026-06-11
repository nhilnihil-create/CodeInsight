		#include<bits/stdc++.h>
#define mod 1500000007
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
	//cin >> t;

	t = 1;

	while(t--){
		ll x;
		cin >> x;

		for(ll i=150;i>=(-150);i--){
			for(ll j=(-150);j<=150;j++){
				if((ll)(pow(i,5)) - (ll)(pow(j,5)) == x){
					cout << i << " " << j << "\n";
					return 0;
				}
			}
		}
	}

	//cout << (ll)(pow(150,5)-pow(-99,5)) << "\n";
	return 0;
}