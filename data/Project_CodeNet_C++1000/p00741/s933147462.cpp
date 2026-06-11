/*
 * B.cpp
 *
 *  Created on: 2017/05/27
 *      Author: aihara
 */

#define MYDEBUG
#include <bits/stdc++.h>

#ifdef MYDEBUG
#define dbp(x) cout << "#x" << ": " << x << endl;
#else
#define dbp(x)
#endif
#define ll long long
using namespace std;

const int maxh = 60;
int w, h;
int c[maxh][maxh];
int di[9] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dj[9] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int ans = 0;
int dfs(int i, int j) {
	if (c[i][j] != 1) {
		return 0;
	}
	c[i][j] = -1;
	for (int k = 0; k < 9; ++k) {
		int ni = i + di[k], nj = j + dj[k];
		if (0 <= ni && ni < h && 0 <= nj && nj < w && c[ni][nj] == 1) {
			dfs(ni, nj);
		}
	}
	return 1;
}

int main() {
	while (cin >> w >> h, w || h) {
		ans = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> c[i][j];
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				ans += dfs(i, j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}