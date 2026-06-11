#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define MAXDATA 200100
vector<vector<int>> to(MAXDATA);
vector<bool> seen(MAXDATA, false);
vector<int> ans(MAXDATA, 0);

void dfs(const vector<vector<int>> &G, int v)
{
    seen[v] = true;
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        ans[next_v] += ans[v];
        dfs(G, next_v);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    rep (i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        to[a - 1].push_back(b - 1);
        to[b - 1].push_back(a - 1);
    }

    rep (i, q)
    {
        int p, x;
        cin >> p >> x;
        ans[p - 1] += x;
    }

    dfs(to, 0);

    rep(i, n)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}