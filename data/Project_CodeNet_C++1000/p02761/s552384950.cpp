#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i].first >> p[i].second;
		p[i].first--;
	}
	for (int i = 0; i <= 999; i++) {
		string s = to_string(i);
		if ((int)s.size() < n) continue;
		bool ok = true;
		for (auto a : p) {
			if (s[a.first] != a.second + '0') ok = false;
		}
		if (ok) {
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}