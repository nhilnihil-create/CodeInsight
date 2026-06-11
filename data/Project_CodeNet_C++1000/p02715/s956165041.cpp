#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(ll (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

ll mod = 1e9+7;

ll pow_mod(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll n,k;
    cin >> n  >> k;
    ll ans = 0;
    vector<ll> vec(k+1,0);
    for(ll i = k;i > 0; i--){
        vec[i] = pow_mod(k/i,n);

        ll sum = 0;
        for(ll j = 2; j*i <= k; j++){
            sum = (sum + vec[j*i]) % mod;
        }
        vec[i] = (vec[i] - sum + mod) % mod;
    }

    rep(i,k+1){
        ll tmp = (i * vec[i]) % mod;
        ans = (ans+tmp) % mod;
    }
    cout << ans << endl;
    return 0;
}
