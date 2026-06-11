// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	int dp0 = 0, dp1 = 1;
	for (int i = 0; i < n; i++) {
		int d = s[i] - '0';
		int dq0 = min(dp0 + d, dp1 + 10 - d);
		int dq1 = min(dp0 + d + 1, dp1 + 9 - d);
		dp0 = dq0;
		dp1 = dq1;
	}
	cout << dp0 << '\n';
	return 0;
}
