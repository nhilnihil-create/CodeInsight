#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve_test() {
	int d, t, s;
	cin >> d >> t >> s;

	int need_t = (d + s - 1) / s;

	cout << (need_t <= t ? "Yes" : "No") << '\n';
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
