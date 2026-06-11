#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i < int(n); i++)

using ll = long long;
using namespace std;

const ll MOD = 1e9+7;

ll modpow(ll a, ll n, ll p) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}

int main(){
    string s; cin >> s;
    ll n = s.length();
	
    ll ans = 0, count = 0;
    rep(i,n){
        if(s[i] == '1'){
            ans += modpow(2,count,MOD) * modpow(3,n-1-i,MOD) % MOD;
            count++;
        }
    }
  	ans += modpow(2,count,MOD);
    cout << ans % MOD << endl;
}