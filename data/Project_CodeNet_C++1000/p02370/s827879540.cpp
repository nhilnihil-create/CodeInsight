#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;

#define MAX_N 500000
#define INF 1145141919

vector<int>G[MAX_N];
list<int> out;
bool V[MAX_N];
int N, M, b, c[MAX_N], d;
int indeg[MAX_N];
queue<int>Q;

void bfs(int s) {
	Q.push(s);
	V[s] = true;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		out.push_back(u);
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indeg[v]--;
			if (indeg[v] == 0 && V[v] == false) { V[v] = true; Q.push(v); }
		}
	}
}

void Tsort() {
	for (int i = 0; i < N; i++) {
		indeg[i] = 0;
	}
	for (int u = 0; u < N; u++) {
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indeg[v]++;
		}
	}
	for (int u = 0; u < N; u++) {
		if (indeg[u] == 0 && V[u] == false) {
			bfs(u);
		}
	}
	b = 0; d = 0;
	for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
		cout << *it << endl;
		c[b] = *it;
		if (b >= 1) {
			for (int i = 0; i < G[c[b - 1]].size(); i++) {
				if (G[c[b - 1]][i] == c[b]) {
					goto F;
				}
				d = 1;
			F:;
			}
		}
		b++;
	}
	//cout << d << endl;
}

int main() {
	int s, t;
	for (int i = 0; i < MAX_N; i++) { G[i].clear(); }
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> s >> t;
		G[s].push_back(t);
	}
	Tsort();
	return 0;
}