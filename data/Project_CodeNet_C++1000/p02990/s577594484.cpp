#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define MOD 1000000007
#define IINF INT_MAX
#define INF 1LL << 30

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
    ll n, k; cin >> n >> k;

    for(int i = 1; i <= k; i++){
        cout << modComb(n - k + 1, i) * modComb(k - 1, i - 1) % MOD << endl;
    }

    return 0;
}
