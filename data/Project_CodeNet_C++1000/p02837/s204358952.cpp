#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;

	cin >> n;

	vector <set<int>> honest(n, set<int>()), unkind(n, set<int>());

	// honest.assign(n, vector<int>());
	// unkind.assign(n, vector<int>());

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		for (int j = 0; j < a; j++) {
			int x, y;
			cin >> x >> y;
			x--;

			if (y) {
				honest[i].insert(x);
			} else {
				unkind[i].insert(x);
			}
		}
	}

	int ans = 0;

	for (int mask = 0; mask < (1 << n); mask++) {
		bool can = true;
		
		// configuration according to mask
		vector <int> h(n, 0);
		vector <int> u(n, 0);

		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				h[i] = 1;
			} else {
				u[i] = 1;
			}
		}

		// compare mask vs testimonies
		for (int i = 0; i < n; i++) {
			if (u[i]) {    // mask[i] is unkind; ignore this
				continue;
			}

			for (int x: honest[i]) {
				if (u[x]) {		// i says x is honest but x is unkind in testimony
					can = false;
				}
			}

			for (int x: unkind[i]) {
				if (h[x]) {		// i says x is unkind but x is honest in testimony
					can = false;
				}
			}
		}

		if (can) {
			ans = max(ans, __builtin_popcount(mask));
		}
	}

	cout << ans << "\n";

	return 0;
}