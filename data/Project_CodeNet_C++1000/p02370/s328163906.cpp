#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int v, e;
vector<int> g[10000];
bool visited[10000];
vector<int> ans;

void dfs(int now)
{
    if (visited[now]) return;
    visited[now] = true;
    for (auto &nxt: g[now]) {
        dfs(nxt);
    }
    ans.emplace_back(now);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int s, t; cin >> s >> t;
        g[s].emplace_back(t);
    }
    for (int i = 0; i < v; i++) dfs(i);
    reverse(ans.begin(), ans.end());
    for (auto &x: ans) cout << x << '\n';
    return 0;
}

