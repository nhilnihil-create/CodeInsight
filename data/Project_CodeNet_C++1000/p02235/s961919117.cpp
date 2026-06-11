#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int q, n, m, dp[1007][1007]; string s, t;
int main() {
	cin >> q;
	while(q--) {
		cin >> s >> t;
		n = s.size(), m = t.size();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]));
			}
		}
		cout << dp[n][m] << endl;
	}
}