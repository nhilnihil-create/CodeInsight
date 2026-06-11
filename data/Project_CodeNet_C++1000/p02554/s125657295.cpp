#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
	
ll mod = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1){
            res = res * a;
			res %= mod;
		}
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}


int main(){
	ll n; cin >> n;
	if(n == 1)cout << 0;
	else{
		cout << (binpow(10, n) - (binpow(9, n) * 2 % mod) + binpow(8, n) + mod) % mod;
	}
    return 0;
}
