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

signed main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> e(n);
    rep(i, n - 1)
    {
        e[i].push_back(i + 1);
        e[i + 1].push_back(i);
    }
    e[x - 1].push_back(y - 1);
    e[y - 1].push_back(x - 1);
    vector<int> ans(n);
    rep(i, n)
    {
        vector<int> visited(n, -1);
        queue<int> q;
        q.push(i);
        visited[i] = 0;
        while (q.size() > 0)
        {
            int a = q.front();
            q.pop();
            for (auto &j : e[a])
            {
                if (visited[j] == -1)
                {
                    visited[j] = visited[a] + 1;
                    q.push(j);
                }
            }
        }
        rep(j, n)
        {
            ans[visited[j]]++;
        }
    }
    rep(i, n - 1)
    {
        cout << ans[i + 1] / 2 << endl;
    }
    return 0;
}