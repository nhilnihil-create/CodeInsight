#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
using ii = pair<int, int>;

int dijkstra(vector<vector<int>> adjlist, int source, int end) {
	priority_queue<ii> pq;
	set<ii> visited;

	pq.push(ii(0, source));

	while (!pq.empty()) {
		ii val = pq.top();
		pq.pop();
		int d = val.first;
		int node = val.second;

		if (visited.find(ii(d % 3, node)) != visited.end()) {
			continue;
		}
		if (node == end && d % 3 == 0) {
			return -d/3;
		}
		for (int i : adjlist[node]) {
			pq.push(ii(d - 1, i));
		}
		visited.insert(make_pair(d % 3, node));
	}
	return -1;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adjlist(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adjlist[u].push_back(v);
	}
	int S, T;
	cin >> S >> T;
	cout << dijkstra(adjlist, S - 1, T - 1);
}