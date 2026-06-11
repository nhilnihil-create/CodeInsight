#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

vector<int> g[N];

int dist[N][N];

void bfs(int st) {
	queue<int> q;
	dist[st][st] = 0;
	q.push(st);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : g[u]) if(dist[st][v] == -1) {
			dist[st][v] = dist[st][u] + 1;
			q.push(v);
		}
	}
}

int ans[N];

int main() {
	memset(dist, -1, sizeof dist);

	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 1; i + 1 <= n; i++) {
		g[i].push_back(i + 1);
		g[i + 1].push_back(i);
	}
	g[x].push_back(y);
	g[y].push_back(x);

	for(int i = 1; i <= n; i++) bfs(i);

	for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) ans[ dist[i][j] ]++;

	for(int i = 1; i < n; i++) {
		printf("%d\n", ans[i]);
	}
}
