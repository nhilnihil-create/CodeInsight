#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> edges;
vector<bool> v;

void dfs(int ver) {
	v[ver] = 1;
	for (int nb : edges[ver]) {
		if (!v[nb]) dfs(nb);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	edges.resize(n + 1);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	int ans{-1};
	for (int i = 1; i <= n; i++) {
		if (!v[i]) dfs(i), ans++;
	}
	cout << ans;
}