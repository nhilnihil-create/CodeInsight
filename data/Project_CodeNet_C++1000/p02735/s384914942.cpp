#include <iostream>
#include <algorithm>
using namespace std;

int H, W; char c[109][109];
int dp[109][109];

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (i == 1 && j == 1) dp[i][j] = 0;
			else {
				dp[i][j] = (1 << 30);
				int score1 = (1 << 30), score2 = (1 << 30);
				if (i >= 2) {
					score1 = dp[i - 1][j];
					if (c[i - 1][j] == '#' && c[i][j] == '.') score1 += 1;
				}
				if (j >= 2) {
					score2 = dp[i][j - 1];
					if (c[i][j - 1] == '#' && c[i][j] == '.') score2 += 1;
				}
				dp[i][j] = min(score1, score2);
			}
		}
	}

	int r = 0; if (c[H][W] == '#') r = 1;
	cout << dp[H][W] + r << endl;
	return 0;
}