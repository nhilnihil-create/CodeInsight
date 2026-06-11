#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;
using ll = long long;

vector<ll> fac, finv, inv;
void COMinit(int max, ll mod){
    fac.resize(max);
    finv.resize(max);
    inv.resize(max);

    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < max; i++)
    {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll COM(int n, int k, ll mod){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}


int main(void)
{
    ll X, Y;
    cin >> X >> Y;

    ll m = 2*Y - X;
    ll n = 2*X - Y;

    if(m <0 || m%3 != 0){
        cout << 0 << endl;
        return 0;
    }

    if(n <0 || n%3 != 0){
        cout << 0 << endl;
        return 0;
    }

    m = m/3;
    n = n/3;

    COMinit(2e6, MOD);

    cout << COM(m+n, n, MOD) << endl;

    return 0;
}
