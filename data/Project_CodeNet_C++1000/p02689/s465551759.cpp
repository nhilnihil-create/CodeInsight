#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool highest(int a, vector<int>& h, vector<vector<int>>& e) {
	for (int c : e[a]) {
		if (h[a] <= h[c]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> h(n+1);
	for (int i=1; i<=n; i++) {
		cin >> h[i];
	}
	vector<vector<int>> e(n+1, vector<int>());
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		cnt += highest(i, h, e);
	}
	cout << cnt;
}
