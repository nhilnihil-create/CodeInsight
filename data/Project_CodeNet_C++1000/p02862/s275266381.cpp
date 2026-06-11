#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
const long long INF = 1LL << 60;
ll mod = 1e9 + 7;

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
    ll x, y;
    cin >> x >> y;
    ll a, b;
    a = 2 * y - x;
    b = 2 * x - y;
    if (a % 3 != 0 || b % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (a < 0 || b < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    a /= 3;
    b /= 3;
    ll ab = a + b;
    ll ans = 1, aa = 1, bb = 1, abab = 1;
    for (ll i = 1; i <= a; i++)
    {
        aa = (aa * i) % mod;
    }
    for (ll i = 1; i <= b; i++)
    {
        bb = (bb * i) % mod;
    }
    for (ll i = 1; i <= ab; i++)
    {
        abab = (abab * i) % mod;
    }
    ans = (abab * modinv(aa, mod)) % mod * modinv(bb, mod);
    cout << ans % mod << endl;
    return 0;
}
