#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> t(m + 1);
    rep (i, n)
    {
        int a, b;
        cin >> a >> b;
        if (a > m)
            continue;
        t[a].push_back(b);
    }

    ll ans = 0;
    priority_queue<int> q;
    for (int i = 1; i <= m; i++)
    {
        for (auto v : t[i])
            q.push(v);
        if (!q.empty())
        {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << endl;
    return 0;
}