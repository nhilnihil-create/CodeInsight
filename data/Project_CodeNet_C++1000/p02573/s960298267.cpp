/*==========================================================================*/
/*
    AUTHOR:    BPZ
	CREATED:   08.09.2020 17:36:01

*/
/*--------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 	int n, m;
 	cin >> n >> m;
 	vector<vector<int>> adj(n + 1);
 	int a, b;
 	for (int i = 0; i < m; i++) {
 		cin >> a >> b;
 		adj[a].push_back(b);
 		adj[b].push_back(a);
 	}
 	vector<bool> visited(n + 1, false);
 	int cnt;
 	function<void(int)> dfs = [&] (int s) {
 		if (visited[s]) {
 			return;
 		}
 		visited[s] = true;
 		cnt++;
 		for (auto u : adj[s]) {
 			dfs(u);
 		}
 	};
 	int ans = -1;
 	for (int i = 1; i < n + 1; i++) {
 		if (visited[i]) continue;
 		cnt = 0;
 		dfs(i);
 		ans = max(cnt, ans);
 	}
 	cout << ans << '\n';
  return 0;
}
 