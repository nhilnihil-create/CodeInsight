#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve_test() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int cost = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			cost += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}

	cout << cost << '\n';
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
