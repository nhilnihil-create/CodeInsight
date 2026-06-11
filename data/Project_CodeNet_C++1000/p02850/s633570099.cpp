#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int k = 1;
vector<int> colors;

void dfs(const vector<vector<int>> &G, vector<bool> &seen, int v, int color, vector<pint> &ab)
{
    seen[v] = true;

    for (int line_id : G[v])
    {
        pint line = ab[line_id];
        int to = line.first;
        if (to == v)
            to = line.second;
        if (seen[to])
            continue;
        color = color % k + 1;
        colors[line_id] = color;
        dfs(G, seen, to, color, ab);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<pint> ab(n - 1);
    vector<vector<int>> G(n + 1);

    rep(i, n - 1)
    {
        cin >> ab[i].first >> ab[i].second;

        G[ab[i].first].emplace_back(i);
        G[ab[i].second].emplace_back(i);
    }

    rep(i, n + 1) k = max(k, int(G[i].size()));

    colors.resize(n - 1);

    vector<bool> seen(n, false);
    dfs(G, seen, 1, 0, ab);

    cout << k << endl;
    rep(i, n - 1) cout << colors[i] << endl;
}