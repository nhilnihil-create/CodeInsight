#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	int n = N * N;
	vector<vector<int>> A(N, vector<int>(N - 1));
	vector<vector<int>> g(n);
	vector<int> indeg(n, 0);
	auto id = [&](int a, int b) -> int {
		return min(a, b) * N + max(a, b);
	};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			cin >> A[i][j];
			--A[i][j];
			if (j > 0) {
				g[id(i, A[i][j - 1])].push_back(id(i, A[i][j]));
				++indeg[id(i, A[i][j])];
			}
		}
	}

	queue<int> que;
	vector<int> cost(n, -1);
	for (int i = 0; i < n; ++i) {
		if (indeg[i] > 0) { continue; }
		que.push(i);
		cost[i] = 1;
	}

	while (!que.empty()) {
		auto u = que.front(); que.pop();
		for (auto v : g[u]) {
			--indeg[v];
			cost[v] = max(cost[v], cost[u] + 1);
			if (indeg[v] == 0) {
				que.push(v);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (indeg[i] > 0) {
			ans = -1;
			break;
		}
		ans = max(ans, cost[i]);
	}
	cout << ans << "\n";

	return 0;
}
