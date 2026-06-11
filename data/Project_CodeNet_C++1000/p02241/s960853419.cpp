#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX_NODE 10000
#define INF 1000000000

using namespace std;

struct Edge {
	int to, w;
};
typedef pair<int, int> P;

vector<Edge> adj[MAX_NODE];
int minW[MAX_NODE];
bool flag[MAX_NODE];

int prim(int n, int start) {
	priority_queue<P, vector<P>, greater<P>> que;
	fill(minW, minW + n, INF);
	fill(flag, flag + n, false);

	int sum = 0;
	minW[start] = 0;
	que.push({0, start});
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int from = p.second;

		if (flag[from])
			continue;

		flag[from] = true;
		sum += p.first;

		for (Edge& e : adj[from])
			if (e.w < minW[e.to]) {
				minW[e.to] = e.w;
				que.push({minW[e.to], e.to});
			}
	}

	return sum;
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x != -1) {
				adj[i].push_back({j, x});
			}
		}
	}

	printf("%d\n", prim(n, 0));

	return 0;
}