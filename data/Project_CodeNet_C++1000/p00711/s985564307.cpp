#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

char board[23 * 23];
int way[4] = { -1,1,-23,23 };
int gCount;

void solve(int pos) {
	gCount++;
	board[pos] = '#';
	for (int i = 0; i < 4; i++) 
		if (board[pos + way[i]] == '.') 
			solve(pos + way[i]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W;
	while (cin >> W >> H, W) {
		for (int i = 0; i < 23 * 23; i++)
			board[i] = '#';
		gCount = 0;
		int s;
		for (int y = 1; y <= H; y++)
			for (int x = 1; x <= W; x++) {
				cin >> board[y * 23 + x];
				if (board[y * 23 + x] == '@') 
					s = y * 23 + x;
			}
		solve(s);
		cout << gCount << endl;
	}
}