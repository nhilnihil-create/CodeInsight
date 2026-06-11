#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i, n, init) for (ll i = init; i < (n); i++)
#define repd(i, n, init) for (ll i = (n); i >= init; i--)
#define repm(i, m) for (auto i = m.begin(); i != m.end(); i++)
#define repb(bit, n, init) for (ll bit = init; bit < (1 << n); ++bit)

vector<ll> fact, invfact;
ll modpower(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
ll inv(ll n)
{
    return modpower(n, MOD - 2, MOD);
}
void COMinit(ll k)
{ //空っぽの配列を二つ
    k++;
    fact.resize(k, 0);
    invfact.resize(k, 0);
    fact[0] = 1;
    repi(i, k, 1)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[k - 1] = inv(fact[k - 1]);
    repd(i, k - 2, 0)
    {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    return;
}
ll nCk(vector<ll> &fact, vector<ll> &invfact, ll n, ll k)
{ //この関数を使う前にCOMinit
    if (k < 0 || n < k)
        return 0LL;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
ll com(ll n, ll k)
{
    ll iv = 1;
    ll fa = 1;
    repi(i, k, 0)
    {
        fa *= (n - i);
        fa %= MOD;
    }
    repi(i, k + 1, 1)
    {
        iv *= inv(i);
        iv %= MOD;
    }
    return fa * iv % MOD;
}

//---------main function----------

int main()
{
    ll x, y;
    cin >> x >> y;
    if ((2 * x - y) % 3 != 0 || (2 * y - x) % 3 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        ll n = (2 * x - y) / 3, m = (2 * y - x) / 3;
        // cout << n << " " << m << endl;
        if (n > m)
            swap(n, m);
        ll ans;
        if (m < 0 || n < 0)
            ans = 0;
        else
            ans = com(n + m, n);

        ans %= MOD;
        if (ans < 0)
            ans += MOD;
        cout << ans << endl;
    }
    return 0;
}