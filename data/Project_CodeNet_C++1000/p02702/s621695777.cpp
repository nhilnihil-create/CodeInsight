#include <bits/stdc++.h>

using namespace std;

int dp[2019], ans;

int main() {
	string s;
	cin >> s;
	dp[0]++;
	for (int i = s.size() - 1, q = 1, p = 0; ~i; i--) {
		ans += dp[(p += (s[i] - '0') * q) %= 2019]++;
		(q *= 10) %= 2019;
	}
	cout << ans;
}
