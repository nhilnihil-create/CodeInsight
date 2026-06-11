#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int H, W, K, ans;
char c[6][6];

int solve(int t1, int t2) {
	int ret = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if ((t1 / (1 << i)) % 2 == 1 && (t2 / (1 << j)) % 2 == 1) {
				if (c[i][j] == '#') ret++;
			}
		}
	}
	return ret;
}

int main() {
	cin >> H >> W >> K;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> c[i][j];
	}
	for (int i = 0; i < (1 << H); i++) {
		for (int j = 0; j < (1 << W); j++) {
			if (solve(i, j) == K) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}