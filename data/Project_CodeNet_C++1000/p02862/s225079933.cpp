#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')

typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int maxn = 1100000;
const int p = 1e9 + 7;
ll inv[maxn];
ll fac[maxn];
ll invfac[maxn];
void init()
{
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
}
ll C(ll n, ll m)
{
    fac[0] = invfac[0] = invfac[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = (ll)fac[i - 1] * i % p;
    }
    for (int i = 2; i <= n; i++)
        invfac[i] = (ll)(p - p / i) * invfac[p % i] % p;
    for (int i = 2; i <= n; i++)
    {
        invfac[i] = (ll)invfac[i - 1] * invfac[i] % p;
    }
    //cout << fac[n] * invfac[m] % p * invfac[n - m] % p << "\n";
    ll res = n < m ? 0 : (ll)fac[n] * invfac[m] % p * invfac[n - m] % p;
    return res;
}
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int X, Y;
    cin >> X >> Y;
    if ((X + Y) % 3 != 0 || (2 * Y - X < 0) || (2 * X - Y < 0))
    {
        cout << 0 << "\n";
    }
    else
    {
        ll m = (2 * X - Y) / 3;
        ll n = (2 * Y - X) / 3;
        cout << C(n + m, n) << "\n";
    }
    return 0;
}