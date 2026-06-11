#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve_test() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
		sum %= 9;
	}
	cout << (sum == 0 ? "Yes" : "No") << '\n';
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
