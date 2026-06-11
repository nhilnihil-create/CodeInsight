#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> res(n);
	map<int,int> exists;
	for (int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		if (x == 1 && y == 0 && n > 1) {
			cout << -1 << endl;
			return 0;
		}
		if (exists.find(x) != exists.end() && exists[x] != y) {
			cout << -1 << endl;
			return 0;
		}
		exists[x] = y;
		res[x-1] = y;
	}
	if (!res[0] && n > 1) res[0] = 1;
	for (int x: res) cout << x;
	cout << endl;
	return 0;
}