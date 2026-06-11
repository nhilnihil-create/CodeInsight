#include <vector>
#include <iostream>
using namespace std;
int H, W, N, x, y;
int main() {
	while (cin >> W >> H, H) {
		vector<vector<bool> > d(H, vector<bool>(W, false));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y; x--, y--;
			d[y][x] = true;
		}
		vector<vector<int> > dp(H, vector<int>(W, 0));
		dp[0][0] = 1;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (d[i][j]) continue;
				if (i >= 1) dp[i][j] += dp[i - 1][j];
				if (j >= 1) dp[i][j] += dp[i][j - 1];
			}
		}
		cout << dp[H - 1][W - 1] << endl;
	}
	return 0;
}