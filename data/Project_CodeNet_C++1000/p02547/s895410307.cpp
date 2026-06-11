#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> d(n);
	for (auto& x: d) {
		cin >> x.first >> x.second;
	}
	for (int i = 0; i < n; ++i) {
		if (d[i].first == d[i].second) {
			int streak = 0;
			while (i < n && d[i].first == d[i].second) {
				++streak; ++i;
			}
			if (streak >= 3) {
				cout << "Yes\n";
				return 0;
			}
			--i;
		}
	}
	cout << "No\n";
	return 0;
}