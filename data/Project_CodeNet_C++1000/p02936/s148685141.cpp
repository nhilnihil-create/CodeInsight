#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, q;
	cin >> n >> q;
	vector<vector<int>> G(n);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	vector<long long> xs(n, 0);
	for (int i = 0; i < q; i++) {
		int p, x;
		cin >> p >> x;
		xs[p-1] += x;
	}
	vector<int> parents(n);
	vector<bool> visited(n, false);
	queue<int> que;
	que.push(0);
	parents[0] = -1;
	vector<long long> counters(n, 0);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		if (parents[v] != -1) {
			counters[v] = counters[parents[v]];
		}
		counters[v] += xs[v];
		for (int i = 0; i < G[v].size(); i++) {
			if (!visited[G[v][i]]) {
				que.push(G[v][i]);
				parents[G[v][i]] = v;
			}
		}
		visited[v] = true;
	}
	for (int i = 0; i < n; i++) {
		cout << counters[i];
		if (i < n-1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}