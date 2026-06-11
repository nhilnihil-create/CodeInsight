#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, n;
	cin >> x >> n;
	vector<int> a(n);
	map<int,int> m;
	for (int& y: a) {
		cin >> y;
		++m[y-x];
	}
	for (int i = 0; i < n; ++i) {
		if (m.find(-i) == m.end()) {
			cout << -i + x << endl;
			return 0;
		}
		else if (m.find(i) == m.end()) {
			cout << i + x << endl;
			return 0;
		}
	}
	cout << -n + x << endl;
	return 0;
}