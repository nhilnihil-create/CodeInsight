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

ll mod = 1000000007;

ll solve(ll c)
{
    if (c == 1)
    {
        return 1;
    }
    else
    {
        for (ll i = 2; i * i <= c; i++)
        {
            if (c % i == 0)
            {
                while (c % i == 0)
                {
                    c /= i;
                }
                return 1 + solve(c);
            }
        }
    }
    return 2;
}

signed main()
{
    ll a, b;
    cin >> a >> b;
    ll c = __gcd(a, b);
    //    cerr << c << endl;
    ll ans = solve(c);
    cout << ans << endl;
    return 0;
}