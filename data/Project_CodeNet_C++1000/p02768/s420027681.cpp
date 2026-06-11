#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll MOD = 1000000007;

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> dp(max(a, b) + 1, 0);

    dp.at(0) = 1;
    rep(i, max(a, b))
    {
        dp.at(i + 1) = ((dp.at(i) * (n - i)) % MOD * modinv(i + 1, MOD)) % MOD;
    }

    ll ans = modpow(2, n, MOD) - 1 - dp.at(a) - dp.at(b);
    while (ans < 0)
    {
        ans += MOD;
    }

    ans %= MOD;

    cout << ans % MOD << endl;
    return 0;
}