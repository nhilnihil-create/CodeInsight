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
ll mypow(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    else
    {
        return a * mypow(a, b - 1);
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<pair<double, pair<int, int>>> pq;
    rep(i, n)
    {
        int a;
        cin >> a;
        pq.push({a, {a, 0}});
    }
    rep(i, m)
    {
        auto a = pq.top();
        pq.pop();
        pq.push({a.first / 2, {a.second.first, a.second.second + 1}});
    }
    ll ans = 0;
    while (!pq.empty())
    {
        auto a = pq.top();
        pq.pop();
        ll rate = 1;
        rep(i, a.second.second)
        {
            rate *=2;
            if(rate>a.second.first){
                break;
            }
        }
        ans += a.second.first / rate;
    }
    cout << ans << endl;
    return 0;
}