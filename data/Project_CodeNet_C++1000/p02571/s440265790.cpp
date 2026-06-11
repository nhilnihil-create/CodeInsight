#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve_test() {
	string s, t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();

	int min_diff = INT_MAX;
	for (int i = 0; i <= n - m; i++) {
		int diff = 0;
		for (int j = i; j < i + m; j++)
			if (s[j] != t[j - i])
				diff++;
		min_diff = min(min_diff, diff);
	}

	cout << min_diff << '\n';
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
