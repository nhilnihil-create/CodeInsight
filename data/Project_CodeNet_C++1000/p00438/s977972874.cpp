# include <iostream>
# include <vector>
# include <limits>
# include <algorithm>
# include <map>
# include <string>
# include <functional>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b&&a != 0 && b != 0) {
		bool block[20][20];
		for (int i = 0; i <20; i++) {
			for (int j = 0; j <20; j++) {
				block[j][i] = false;
			}
		}
		int dp[20][20];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int c, d;
			cin >> c >> d;
			block[d][c] = true;
		}
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				if (block[j][i] == true) {
					dp[j][i] = 0;
				}
				else if (j == 1 && i == 1) {
					dp[j][i] = 1;
				}
				else if (j == 1) {
					if (dp[j][i - 1] != 0) {
						dp[j][i] = 1;
					}
					else {
						dp[j][i] = 0;
					}
				}
				else if (i == 1) {
					if (dp[j - 1][i] != 0) {
						dp[j][i] = 1;
					}
					else {
						dp[j][i] = 0;
					}
				}
				else {
					dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
				}
			}
		}
		cout << dp[b][a] << endl;
	}
}