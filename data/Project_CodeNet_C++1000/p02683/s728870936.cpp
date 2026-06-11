#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n, m, x; cin >> n >> m >> x;
	vector<int> p(n);
	vector<vector<int>> a(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		cin >> p[i];
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	
	int mn = INT_MAX;
	for (int i=0; i<(1<<n); i++) {
		int cost = 0;
		vector<int> u(m, 0);
		for (int j=0; j<n; j++) {
			if ((i>>j)&1==1) {
				cost += p[j];
				for (int k=0; k<m; k++) {
					u[k] += a[j][k];
				}
			}
		}
		if (*min_element(u.begin(), u.end()) >= x) {
			mn = min(mn, cost);
		}
	}
	if (mn < INT_MAX) {
		cout << mn;
	}
	else {
		cout << -1;
	}
}
