#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[100000];
vector<int> color(100000);
vector<bool> vis(100000, false);
int k = 0;

void dfs(int v, int cor_inc) {
    vis[v] = true;
    int cor = 1;
    for (pair<int, int> ui : adj[v]) {
        int u = ui.first;
        if (vis[u])
            continue;
        if (cor == cor_inc)
            cor++;
        color[ui.second] = cor;
        dfs(u, cor);
        cor++;
    }
    k = max(k, cor - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    dfs(0, 0);
    cout << k << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << color[i] << endl;
    }
	return 0;
}