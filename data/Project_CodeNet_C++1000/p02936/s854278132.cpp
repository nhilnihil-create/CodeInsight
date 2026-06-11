#include <bits/stdc++.h>
using namespace std;


int sum = 0;




void bfs(int u, vector<vector<int>> &g, vector<int> &points, vector<int> &ans, vector<bool> &visited) {
	if (visited[u]) return;
	visited[u] = true;
	sum += points[u];
	ans[u] = sum;
	for (int v : g[u]) {
		bfs(v, g, points, ans, visited);
	}

	sum -= points[u];
}

int main() {
	
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<int> points(n);
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		points[x] += y;
	}
	vector<int> ans(n);
	vector<bool> visited(n);
	bfs(0, g, points, ans, visited);
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}