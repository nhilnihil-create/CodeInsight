#include <bits/stdc++.h>
using namespace std;

vector<int> adj[234567];
vector<int> elements;
vector<int> visited;

int dfs(int src) {
	visited[src] = true;
	int cnt = 1;
	for (int node: adj[src]) {
		if (!visited[node]) {
			cnt += dfs(node);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	visited.resize(n+1);
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			elements.push_back(dfs(i));
		}
	}
	cout << *max_element(elements.begin(), elements.end()) << endl;
	return 0;
}