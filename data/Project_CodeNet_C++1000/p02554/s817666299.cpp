#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

ll N;
const int MOD = 1.0e9 + 7;

ll pow_mod(ll n, ll k, ll mod) {
    if (k == 0) return 1;
    else if (k % 2 == 1) {
        return pow_mod(n, k-1, mod) * n % mod;
    }
    else {
        ll tmp = pow_mod(n, k/2, mod);
        return tmp * tmp % mod;
    }
}

ll neg_mod(ll n, ll mod)  {
    ll res = n % mod;
    if (res < 0) res += mod;
    return res;
}

int main() {
    cin >> N;

    ll ans = pow_mod(10, N, MOD);
    ans = neg_mod(ans - pow_mod(9, N, MOD), MOD);
    ans = neg_mod(ans - pow_mod(9, N, MOD), MOD);
    ans = (ans + pow_mod(8, N, MOD)) % MOD;
    
    cout << ans << endl;

    return 0; 
}