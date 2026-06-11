#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int x = s.size(), y = t.size();
	int dp[x + 1][y + 1] = { 0 };
	int a = 0, b = 0;
	for (int i = 0; i <= x; i++) {
		dp[i][0] = a;
		a++;
	}
	for (int i = 0; i <= y; i++) {
		dp[0][i] = b;
		b++;
	}
	int c[3] = { 0 };
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			c[0] = dp[i - 1][j] + 1;
			c[1] = dp[i][j - 1] + 1;
			if (s.at(i - 1) == t.at(j - 1)) {
				c[2] = dp[i - 1][j - 1];
			}
			else {
				c[2] = dp[i - 1][j - 1] + 1;
			}
			sort(c, c + 3);
			dp[i][j] = c[0];
		}
	}
	cout << dp[x][y] << endl;
}
