#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

void dfs(const vector<vector<int>> &G, vector<bool> &seen, int v, ll sum, vector<ll> &values)
{
    seen[v] = true;
    values[v] += sum;
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        dfs(G, seen, next_v, values[v], values);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    vector<ll> values(n + 1, 0);
    vector<bool> seen(n + 1, false);

    for (int i = 0; i < q; ++i)
    {
        int p, x;
        cin >> p >> x;

        values[p] += x;
    }

    dfs(graph, seen, 1, 0, values);

    for (int i = 1; i <= n; ++i)
        cout << values[i] << " ";
    cout << endl;
}