#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1, vector<int>(n - 1, 0));
	vector<vector<pair<int, int>>> index(n + 1, vector<pair<int, int>>(n + 1, make_pair(-1, -1)));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - 1; j++) {
			cin >> v[i][j];
			index[i][v[i][j]] = make_pair(i, j);
		}
	}
	vector<vector<int>> remain(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n - 1; j++) {
			int x = min(i, v[i][j]), y = max(i, v[i][j]);
			remain[x][y]++;
		}
	}
	vector<pair<int, int>> vp1, vp2;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (remain[i][j] == 0) {
				vp1.push_back(make_pair(i, j));
			}
		}
	}
	int res = 0;
	int c = 0;
	while (vp1.size() > 0) {
		vp2.clear();
		res++;
		for (auto p : vp1) {
			c++;
			auto p1 = index[p.first][p.second];
			auto p2 = index[p.second][p.first];
			int x, y;
			if (p1.second + 1 < n - 1) {
				x = min(v[p1.first][p1.second + 1], p1.first);
				y = max(v[p1.first][p1.second + 1], p1.first);
				remain[x][y]--;
				if (remain[x][y] == 0) vp2.push_back(make_pair(x, y));
			}
			if (p2.second + 1 < n - 1) {
				x = min(v[p2.first][p2.second + 1], p2.first);
				y = max(v[p2.first][p2.second + 1], p2.first);
				remain[x][y]--;
				if (remain[x][y] == 0) vp2.push_back(make_pair(x, y));
			}
		}
		vp1 = vp2;
	}
	if (c != n * (n - 1) / 2) 
		cout << -1 << endl;
	else
		cout << res << endl;
}
