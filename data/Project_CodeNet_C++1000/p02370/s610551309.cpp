//DFS na neusmerenim grafovima
#include <bits/stdc++.h>
#define INF INT_MAX
#define MOD 100000007
#define MAX_V 100000
#define MAX_E 100000

using namespace std;

int V, E;
vector<int> adj[MAX_V];
int visited[MAX_V];
int parent[MAX_V];
stack<int> stk;
void DFS(int v) {
	visited[v] = 1;
	int d = adj[v].size();
	for (int i = 0; i<d; ++i) {
		if (visited[adj[v][i]] == 1) {
			cout << "IMA CIKLUS";
			exit(0);
		}
		if(visited[adj[v][i]]==0)
		DFS(adj[v][i]);
	}
	visited[v]=2;
	stk.push(v);
	return;
}

int main() {
	memset(parent, -1, sizeof(parent));
	ios::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 0; i<E; ++i) {
		int u, v;
		cin >> u >> v;
		/*u--;
		v--;*/
		adj[u].push_back(v);
	}
	for (int i = 0; i<V; ++i) {
		if (!visited[i])DFS(i);
	}
	while (!stk.empty()) {
		cout << stk.top() << " ";
		cout << endl;
		stk.pop();
	}
	return 0;
}
/*
4 4
1 2
2 3
3 4
1 4

*/



