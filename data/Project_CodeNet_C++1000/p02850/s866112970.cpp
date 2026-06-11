#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX { 100010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

vector<ii> adj[MAX];

void dfs(int u, int p, int color, int& maxc, vector<int>& ans)
{
    int c = 0;

    for (auto q : adj[u])
    {
        auto v = q.first, e = q.second;

        if (v == p)
            continue;

        if (c + 1 == color)
            ++c;

        ans[e] = ++c;

        dfs(v, u, c, maxc, ans);
    }

    maxc = max(maxc, c);
}

pair<int, vector<int>> solve(int N)
{
    int maxc = 0;
    vector<int> ans(N - 1, 0);

    dfs(1, 0, -1, maxc, ans);

    return { maxc, ans };
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(ii(b, i));
        adj[b].push_back(ii(a, i));
    }

    auto ans = solve(N);

    cout << ans.first << endl;

    for (auto x : ans.second)
        cout << x << '\n';

    return 0;
}
