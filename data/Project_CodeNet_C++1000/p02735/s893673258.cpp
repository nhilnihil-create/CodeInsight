#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>>board(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)cin >> board.at(i).at(j);
	}
	vector<vector<int>>dp(h, vector<int>(w,-1));
	if (board.at(0).at(0) == '.')dp.at(0).at(0) = 0;
	else dp.at(0).at(0) = 1;
	for (int i = 1; i < w; i++) {
		int x = 0;
		if (board.at(0).at(i - 1) == '.' && board.at(0).at(i) == '#')x++;
		dp.at(0).at(i) = dp.at(0).at(i-1) + x;
	}
	for (int i = 1; i < h; i++) {
		int x = 0;
		if (board.at(i - 1).at(0) == '.' && board.at(i).at(0) == '#')x++;
		dp.at(i).at(0) = dp.at(i - 1).at(0) + x;
	}
	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			int x = 0;
			if (board.at(i).at(j - 1) == '.' && board.at(i).at(j) == '#')x++;
			x += dp.at(i).at(j - 1);
			int y = 0;
			if (board.at(i - 1).at(j) == '.' && board.at(i).at(j) == '#')y++;
			y += dp.at(i - 1).at(j);
			dp.at(i).at(j) = min(x, y);
		}
	}
	cout << dp.at(h - 1).at(w - 1) << endl;
}