#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {

	int INF = 10000000;

	int n;
	scanf("%d", &n);

	vector<pair<int, int>> G[n];
	for (int i = 0; i < n; ++i) {
		int from;
		scanf("%d", &from);

		int v;
		scanf("%d", &v);

		for (int j = 0; j < v; ++j) {
			int to;
			int w;
			scanf("%d %d", &to, &w);
			G[from].push_back(make_pair(to, w));
		}
	}

	int C[n];
	for (int i = 0; i < n; ++i)
		C[i] = INF;

	int color[n];
	int WHITE = 0;
	int BLACK = 1;
	for (int i = 0; i < n; ++i)
		color[i] = WHITE;

	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, 0));
	C[0] = 0;
	while (!PQ.empty()) {
		int u = PQ.top().second;
		PQ.pop();
		color[u] = BLACK;
		for (int i = 0; i < (int) G[u].size(); ++i) {
			auto c = G[u][i];
			if (color[c.first] != BLACK && c.second + C[u] < C[c.first]) {
				C[c.first] = c.second + C[u];
				PQ.push(make_pair(C[c.first] * -1, c.first));
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << i << " " << C[i] << endl;
	}

	return 0;
}