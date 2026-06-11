#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;

ll binary_pow(ll n, ll p)
{
    return p ? binary_pow(n * n % MOD, p >> 1) * (p & 1 ? n : 1) % MOD : 1;
}

ll combination(ll n, ll r)
{
    ll x = 1, y = 1;
    r = min(r, n - r);
    rep (i, r)
    {
        x = x * (n - i) % MOD;
        y = y * (i + 1) % MOD;
    }
    return x * binary_pow(y, MOD - 2) % MOD;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    ll ans = binary_pow(2, n) - combination(n, a) - combination(n, b) - 1;
    while (ans < 0)
        ans += MOD;

    cout << ans % MOD << endl;
    return 0;
}