#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair<int, int>> tree[100010];
vector <int> visited;
set <int> coloured[100010];
vector <int> ans;
int k;

void dfs(int u, int p, int pc)
{
    int c = 1;

    for (auto v: tree[u])
    {
        if (v.first == p)
            continue;

        coloured[u].insert(c);
        coloured[v.first].insert(c);
        
        if (c == pc)
            c++;

        k = max(k, c);
        ans[v.second] = c;
        dfs(v.first, u, c);
        c++;
    }
}

int main()
{
    cin >> n;

    vector <pair<int, int>> edges;

    for (int i = 1; i < n; i++)
    {
        int u, v;

        cin >> u >> v;

        edges.push_back({u, v});

        tree[u].push_back({v, i-1});
        tree[v].push_back({u, i-1});
    }

    ans.assign(n-1, 0);
    dfs(1, 0, 0);

    cout << k << "\n";
    for (int c: ans)
    {
        cout << c << "\n";
    }

    return 0;
}