#include <bits/stdc++.h>
using namespace std;
	
vector<int> adj[123456];
vector<int> hs;

bool is_good(int x) {
	for (int node: adj[x]) {
		if (hs[node] >= hs[x]) 
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, h;
	cin >> n >> m;
	hs.resize(n+1);
	for (int i = 1; i <= n; ++i) cin >> hs[i];
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += is_good(i);
	}
	cout << cnt << endl;
	return 0;
}