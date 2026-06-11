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
    int n, m;
    cin >> n >> m;
    vector<ll> dp(n + 1);
    vector<bool> isa(n + 1, false);
    dp[0] = 1;
    dp[1] = 1;
    rep(i, m)
    {
        int a;
        cin >> a;
        isa[a] = true;
    }
    rep(i, n + 1)
    {
        if (i > 1)
        {
            if (!isa[i - 1])
            {
                dp[i] += dp[i - 1];
            }
            if (!isa[i - 2])
            {
                dp[i] += dp[i - 2];
            }
            dp[i] %= mod;
            //            cout << dp[i] << endl;
        }
    }
    cout << dp[n] << endl;
    return 0;
}