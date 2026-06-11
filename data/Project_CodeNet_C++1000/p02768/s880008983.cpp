#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

const ll MOD = 1e9 + 7;

// 繰り返し二乗法
ll modPow(ll x, ll a){
    if(a == 1) return x;
    if(a % 2) return (x * modPow(x, a - 1)) % MOD;
    ll t = modPow(x, a / 2);
    return (t * t) % MOD;
}

ll modInv(ll x){
    return modPow(x, MOD - 2);
}

ll modPerm(ll n, ll k){
    ll ret = 1;
    for(int i = 0; i < k; i++){
        ret = (ret * (n - i)) % MOD;
    }
    return ret;
}

ll modComb(ll n, ll k){
    ll a, b;
    a = modPerm(n, k);
    b = modPerm(k, k);
    return (a * modInv(b)) % MOD;
}

int main() {
    ll n, a, b; cin >> n >> a >> b;

    ll ans = (modPow(2, n) - 1 - modComb(n, a) - modComb(n, b)) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}
