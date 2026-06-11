#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve_test() {
	int n, x, t;
	cin >> n >> x >> t;
	cout << (n + x - 1) / x * t << '\n';
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
