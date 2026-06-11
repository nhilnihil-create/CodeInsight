#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 3e5 + 7;



int main() {
	fastIO;
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < 1000; i++) {
		string s = to_string(i);
		bool valid = (int)s.size() == n;
		for (auto j : v) {
			if (s[j.first - 1] != j.second + '0')
				valid = false;
		}
		if (valid) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}