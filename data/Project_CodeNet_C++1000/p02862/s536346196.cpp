#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000007
#define MAX 1001000
#define all(x) (x).begin(), (x).end()
#define max(x) *max_element(all(x))
#define min(x) *min_element(all(x))

using namespace std;

ll modinv(ll a, ll m) //法mにおける，aの逆元を求める
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b, swap(a, b);
        u -= t * v, swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

ll modpow(ll a, ll n, ll m) //a^n(mod m)を求める
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

ll fac[MAX], finv[MAX], inv[MAX];

//二項係数の計算
void comint()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll com(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll x, y;
    cin >> x >> y;
    if ((x + y) % 3 != 0)
        cout << 0 << endl;
    else
    {
        ll n = (-x + 2 * y) / 3;
        ll m = (2 * x - y) / 3;
        if (n < 0 || m < 0)
            cout << 0 << endl;
        else
        {
            comint();
            cout << com(n + m, n) << endl;
        }
    }
}