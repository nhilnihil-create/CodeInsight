#include <bits/stdc++.h>
using namespace std;

int main() {
	// 0-ind
	int N, M; cin >> N >> M;
	vector<vector<int>> g(N, vector<int>(0));
	for (int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;
		A--; B--;
		g[A].push_back(B);
		g[B].push_back(A);
	}
	int ans = 0;
	vector<bool> r(N, false);
	queue<int> q;

	for (int s = 0; s < N; s++) {
		if (r[s]) continue;
		r[s] = true;
		q.push(s);
		int temp = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : g[u]) {
				if (r[v]) continue;
				r[v] = true;
				q.push(v);
				temp++;
			}
		}
		if (temp > ans) ans = temp;
	}
	cout << ans << endl;
}