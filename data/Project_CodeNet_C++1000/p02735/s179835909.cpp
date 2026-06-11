
// Problem : A - Range Flip Find Route
// Contest : AtCoder - AtCoder Grand Contest 043
// URL : https://atcoder.jp/contests/agc043/tasks/agc043_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

void min_self(int& a, int b) {
	a = min(a, b);
}

int main() {
	int H;
	int W;
	cin >> H >> W;
	vector<string> grid(H);
	for (int row = 0; row < H; row++) {
		cin >> grid[row];
	}
	vector<vector<int>> dp(H, vector<int>(W, INF));
	
	dp[0][0] = grid[0][0] == '#';
	for (int row = 0; row < H; row++) {
		for (int col = 0; col < W; col++) {
			if (row == 0 && col == 0) {
				continue;
			}
			if (row != 0) {
				min_self(dp[row][col], dp[row - 1][col] + (grid[row][col] == '#' && grid[row - 1][col] == '.'));
			}
			if (col != 0) {
				min_self(dp[row][col], dp[row][col - 1] + (grid[row][col] == '#' && grid[row][col - 1] == '.'));
			}
		}
	}
	cout << dp[H - 1][W - 1] << "\n";
}














