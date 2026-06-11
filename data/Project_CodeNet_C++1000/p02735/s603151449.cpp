#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

void chmin(int& a, int b) { if (a > b) { a = b; } };

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; ++i) { cin >> s[i]; }

	auto cost = [&](char a, char b) -> int {
		return (a == '.' && b == '#');
	};

	vector<vector<int>> d(H, vector<int>(W, 1e8));
	d[0][0] = (s[0][0] == '#');
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (j + 1 < W) {
				chmin(d[i][j + 1], d[i][j] + cost(s[i][j], s[i][j + 1]));
			}
			if (i + 1 < H) {
				chmin(d[i + 1][j], d[i][j] + cost(s[i][j], s[i + 1][j]));
			}
		}
	}
	cout << d[H - 1][W - 1] << endl;

	return 0;
}
