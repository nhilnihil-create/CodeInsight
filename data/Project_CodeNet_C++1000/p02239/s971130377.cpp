#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int src, int n, vector<vector<int> > G);

int main() {
	int n;
	cin >> n;
	vector<vector<int> > G(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int v_j;
			cin >> v_j;
			G[u - 1][v_j - 1] = 1;
		}
	}
	bfs(0, n, G);
}

void bfs(int src, int n, vector<vector<int> > G) {
	vector<int> D(n, -1);
	D[src] = 0;
	queue<int> Q;
	Q.push(src);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int dst = 0; dst < n; dst++)
			if (G[cur][dst] == 1 && D[dst] == -1){
				D[dst] = D[cur] + 1;
				Q.push(dst);
			}
	}
	for (int i = 0; i < n; i++)
		cout << i + 1 << " " << D[i] << endl;
}