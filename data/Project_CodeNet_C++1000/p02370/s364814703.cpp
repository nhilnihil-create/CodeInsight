#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

#define N 100000
static const long long FAR = (1L << 31);

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

vector<int> G[N];
vector<int> out;
bool Visited[N];
int n, m;
int indeg[N];

void bfs(int s){
	queue<int>q; q.push(s);
	Visited[s] = true;
	while (!q.empty()){
		int u = q.front(); q.pop();
		out.push_back(u);
		for (int i = 0; i < G[u].size(); ++i){
			int v = G[u][i];
			indeg[v]--;
			if (indeg[v] == 0 && !Visited[v]){
				Visited[v] = true;
				q.push(v);
			}
		}
	}
}

void tsort(){
	for (int i = 0; i < n; ++i) indeg[i] = 0;

	for (int u = 0; u < n; ++u){
		for (int j = 0; j < G[u].size(); ++j){
			int v = G[u][j];
			indeg[v]++;
		}
	}

	for (int u = 0; u < n; ++u) if (indeg[u] == 0 && !Visited[u]) bfs(u);
	for (int i = 0; i < out.size(); ++i) cout << out[i] << endl;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i) Visited[i] = false;
	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		G[u].push_back(v);
	}
	tsort();
	return 0;
}