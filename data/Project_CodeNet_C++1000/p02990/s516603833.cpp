#include <iostream>
#include <vector>

using namespace std;

#define MAX 3000

typedef long long ll;

ll mod = 1e9+7;
vector<ll> fac(MAX), finv(MAX), inv(MAX);

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (int i = 1; i < MAX-1; i++) {
        fac[i+1] = fac[i] * (i+1) % mod;
        inv[i+1] = mod - inv[mod%(i+1)]*(mod/(i+1))%mod;
        finv[i+1] = finv[i]*inv[i+1] % mod;
    }
}

ll COM(ll n, ll k) {
    if (k < 0 || n < k)
        return 0;
    
    ll res = 1;
    res *= fac[n]*finv[k]%mod*finv[n-k]%mod;
    return res;
}

int main() {
    ll n, k;    cin >> n >> k;

    COMinit();

    for (int i = 1; i <= k; i++) {
        cout << COM(n-k+1, i)*COM(k-1, i-1) % mod << endl;
    }

    return 0;
}