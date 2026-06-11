#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> G(n); // (v number, edge number)
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		G[a-1].push_back(make_pair(b-1, i));
		G[b-1].push_back(make_pair(a-1, i));
	}
	int max = 0;
	for (auto e : G) {
		if (max < e.size())
			max = e.size();
	}
	cout << max << endl;


	vector<int> colors(n-1);
	fill(colors.begin(), colors.end(), -1);

	queue<int> q;
	int root = -1;
	for (int i = 0; i < n; i++) { // find root
		if (G[i].size() == 1) {
			root = i;
			break;
		}
	}
	q.push(root);
	vector<int> u(n, -1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		int col = 1;
		for (auto e : G[v]) {
			if (colors[e.second] != -1) {
				continue;
			}
			if (col == u[v])
				col++;
			colors[e.second] = col;
			u[e.first] = col;
			q.push(e.first);
			col++;
		}
	}

	for (auto e : colors)
		cout << e << endl;
	return 0;
}