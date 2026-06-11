#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GRAY 1
static const int MAXV = 10000, MAXE = 100000;
int V, E;
vector<int> G[MAXV];
list<int> ans;
int col[MAXV];
int indeg[MAXV];

void bfs(int s) {
	queue<int> Q;
	Q.push(s);
	col[s] = GRAY;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		ans.push_back(u);
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indeg[v]--;
			if (indeg[v] == 0 && col[v] == WHITE) {
				Q.push(v);
				col[v] = GRAY;
			}
		}
	}
}

void topologicalsort() {
	for (int u = 0; u < V; u++) {
		if (indeg[u] == 0 && col[u] == WHITE) {
			bfs(u);
		}
	}
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < V; i++) {
		col[i] = WHITE;
		indeg[i] = 0;
	}
	for (int i = 0; i < E; i++) {
		int s, t;
		cin >> s >> t;
		G[s].push_back(t);
		indeg[t]++;
	}
	topologicalsort();
	for (int i = 0; i < V; i++) {
		cout << ans.front() << endl;
		ans.pop_front();
	}
	return 0;
}

