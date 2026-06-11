#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int H, W, K;
	cin >> H >> W >> K;

	vector<string> c(H);
	for (int i = 0; i < H; ++i) {
		cin >> c[i];
	}

	int ans = 0;
	for (int h = 0; h < (1 << H); ++h) {
		vector<string> tmp = c;
		for (int i = 0; i < H; ++i) {
			if (h & (1 << i)) {
				for (int k = 0; k < tmp[i].size(); ++k) {
					tmp[i][k] = 'x';
				}
			}
		}

		for (int w = 0; w < (1 << W); ++w) {
			vector<string> tmp2 = tmp;

			for (int j = 0; j < W; ++j) {
				if (w & (1 << j)) {
					for (int k = 0; k < tmp2.size(); ++k) {
						tmp2[k][j] = 'x';
					}
				}
			}

			int count = 0;
			for (int i = 0; i < tmp2.size(); ++i) {
				for (int j = 0; j < W; ++j) {
					if (tmp2[i][j] == '#') {
						count++;
					}
				}
			}

			if (count == K) {
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
