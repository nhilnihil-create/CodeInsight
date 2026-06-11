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

signed main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> as(n);
    vector<pair<ll, ll>> vp;
    rep(i, n)
    {
        cin >> as[i];
    }
    rep(i, n)
    {
        int l = 0;
        int r = 0;
        rep(j, n)
        {
            if (j < i && as[j] < as[i])
            {
                l++;
            }
            else if (i < j && as[j] < as[i])
            {
                r++;
            }
        }
        vp.push_back({l, r});
    }
    // rep(i, n)
    // {
    //     cout << vp[i].first << " " << vp[i].second << endl;
    // }
    ll ans = 0;
    rep(i, n)
    {
        ll l = vp[i].first;
        ll r = vp[i].second;
        ans += (k * r % mod + k * (k - 1) / 2 % mod * (l + r) % mod) % mod;
        ans %= mod;
    }
    cout << ans % mod << endl;
    return 0;
}