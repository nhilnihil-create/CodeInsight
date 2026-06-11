#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INF 1010101010

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	vector<vector<int>> dp(h, vector<int>(w, INF));
	dp[0][0] = s[0][0] == '#' ? 1 : 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i != 0) {
				if (s[i][j] == s[i - 1][j]) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = dp[i - 1][j] + 1;
				}
			}
			if (j != 0) {
				if (s[i][j] == s[i][j - 1]) {
					dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				} else {
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
				}
			}
		}
	}
	dp[h - 1][w - 1] += s[h - 1][w - 1] == '#' ? 1 : 0;

	cout << dp[h - 1][w - 1] / 2 << endl;

	return 0;
}