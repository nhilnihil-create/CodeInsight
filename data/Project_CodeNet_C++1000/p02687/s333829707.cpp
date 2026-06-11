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
	//cin >> t;

	t = 1;
	while(t--){
		string s;
		cin >> s;

		if(s == "ABC"){
			cout << "ARC";
		}
		else{
			cout << "ABC";
		}
	}
	return 0;
}