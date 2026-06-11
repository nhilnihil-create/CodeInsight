#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int ll;
const int MOD = 1000000007;

ll mod_pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a){
    return mod_pow(a, MOD-2);
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = mod_pow(2, n);
    ll ma = 1;
    for(int i = 0; i < a; i++){
        ma *= (n-i);
        ma %= MOD;
        ma *= modinv(a-i);
        ma %= MOD;
    }
    ll mb = 1;
    for(int i = 0; i < b; i++){
        mb *= n-i;
        mb %= MOD;
        mb *= modinv(b-i);
        mb %= MOD;
    }
    ans += MOD - ma;
    ans %= MOD;
    ans += MOD - mb;
    ans %= MOD;
    ans += MOD - 1;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}