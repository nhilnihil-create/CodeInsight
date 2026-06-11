// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const int inf = 1e9;

int n, m, dis[N], from[N];
vector<int> adj[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 0; i < n; i++) {
		dis[i] = inf;
	}

	dis[0] = 0;

	queue<int> q;

	q.push(0);

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : adj[u]) {
			if(dis[v] > dis[u] + 1) {
				from[v] = u;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

	for(int i = 1; i < n; i++) {
		if(dis[i] == inf) {
			cout << "No";
			exit(0);
		}
	}

	cout << "Yes\n";

	for(int i = 1; i < n; i++) {
		cout << from[i] + 1 << "\n";
	}

	
	return 0;
}
