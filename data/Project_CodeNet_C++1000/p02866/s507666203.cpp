#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

//ll mod = 1000000007;
ll mod = 998244353;
ll powmod(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    else if (b % 2 == 0)
    {
        return powmod((a * a) % mod, b / 2);
    }
    else
    {
        return (a * powmod((a * a) % mod, b / 2)) % mod;
    }
}

signed main()
{
    ll n;
    cin >> n;
    vi v(n);
    int dmax = 0;
    bool f = false;
    rep(i, n)
    {
        int d;
        cin >> d;
        if (i == 0 && d != 0)
        {
            f = true;
        }
        v[d]++;
        chmax(dmax, d);
    }
    if (f)
    {
        cout << 0 << endl;
        return 0;
    }
    if (v[0] > 1)
    {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i = 1; i <=dmax;i++)
    {
        ans = ans * powmod(v[i - 1], v[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}