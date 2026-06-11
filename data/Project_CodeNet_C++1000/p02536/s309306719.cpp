#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+15;
int n, m, x, y, res;
vector<int> adj[maxn];
bool visited[maxn];

void dfs(int node) {
    visited[node] = true;
    for (int u: adj[node]) {
        if (!visited[u])
            dfs(u);
    }
}
int count() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    res = count();
    cout << res-1;
}