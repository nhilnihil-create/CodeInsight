#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int mxN = 1e5 + 5, mod = 1e9 + 7;
vector<int> adj[mxN];
long long answer = 1, k;

void dfs(int node, int parent = -1) {
	long long cur = parent == -1 ? k - 1 : k - 2;
	for(int x : adj[node]) {
		if(x == parent)
			continue;
		if(cur <= 0) {
			answer = 0;
			return;
		}
		answer = answer * cur % mod;
		--cur;
		dfs(x, node);
	}
}

int main() {
	int n;
	cin >> n >> k;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	answer = k;
	dfs(1);
	cout << answer;
}
