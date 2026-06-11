#include <iostream>
#include <vector>
using namespace std;

const int mxN = 2e5 + 5;
vector<int> adj[mxN];
long long cnt[mxN];

void dfs(int node, int parent = - 1, long long add = 0) {
	int cur = cnt[node];
	cnt[node] += add;
	add += cur;
	for(int x : adj[node]) {
		if(x == parent)
			continue;
		dfs(x, node, add);
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while(q--) {
		int v, c;
		cin >> v >> c;
		cnt[v] += c;
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)
		cout << cnt[i] << ' ';
}