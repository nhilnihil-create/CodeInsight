#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n; cin >> n;
	vector<int> add(n), sub(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		add[i] = x + y;
		sub[i] = x - y;
	}
	sort(add.begin(), add.end());
	sort(sub.begin(), sub.end());
	cout << max(add[n-1] - add[0], sub[n-1] - sub[0]) << '\n';
	return 0;
}