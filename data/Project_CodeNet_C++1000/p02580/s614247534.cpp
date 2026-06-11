#include "bits/stdc++.h"
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> row(n, 0);
	vector<int> col(m, 0);

	vector<vector<int>> adj(n, vector<int>());

	while(k--) {
		int x, y; cin >> x >> y;
		x--;
		y--;
		row[x]++;
		col[y]++;
		adj[x].push_back(y);
	}

	int row_max = *max_element(row.begin(), row.end());
	int col_max = *max_element(col.begin(), col.end());

	int mx_col_cnt = 0;
	for(int i = 0; i < m; ++i) {
		if(col[i] == col_max) {
			mx_col_cnt++;
		}
	}

	bool found = false;
	for(int i = 0; i < n; ++i) {
		if(row[i] != row_max) continue;
		int cnt = 0;
		for(auto j : adj[i]) {
			cnt += col[j] == col_max;
		}
		if(cnt < mx_col_cnt) 
			found = true;
		if(found)
			break;
	}

	cout << (found ? (row_max + col_max) : (row_max + col_max - 1)) << '\n';

	return 0;
}