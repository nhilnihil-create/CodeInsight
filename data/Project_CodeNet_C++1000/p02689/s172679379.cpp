#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 10000000000
#define PI 3.141592653589793

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> h(n);
	vector<int> a(m);
	vector<int> b(m);
	vector<vector<int>> table(n, vector<int>(0));
	vector<bool> check(n, false);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		table[a[i]-1].push_back(b[i]-1);
		table[b[i]-1].push_back(a[i]-1);
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			for (int j = 0; j < table[i].size(); j++) {
				if (h[i] <= h[table[i][j]]) {
					check[i] = true;
					break;
				}
				check[table[i][j]] = true;
			}
			if (!check[i]) ans++;
		}
	}

	cout << ans;
	return 0;
}