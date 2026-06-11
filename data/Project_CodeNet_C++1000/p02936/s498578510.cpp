#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool seen[200010];
int dist[200010] = {};
vector<vector<int>> tree(200010);
void dfs(int i, int prev) {
    seen[i] = 1;
    if (i != 0) dist[i] += dist[prev];
    for (auto next : tree[i])
        if (!seen[next]) dfs(next, i);
}

signed main() {
    int n, q;
    cin >> n >> q;
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        tree[--a].push_back(--b);
        tree[b].push_back(a);
    }
    rep(i, 0, q) {
        int p, x;
        cin >> p >> x;
        dist[--p] += x;
    }
    dfs(0, 0);
    rep(i, 0, n) { cout << dist[i] << "\n"; }
}