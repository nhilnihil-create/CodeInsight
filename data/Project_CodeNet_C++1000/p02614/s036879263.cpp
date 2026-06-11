#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int h, w, k;
	string c[6];
	int ans = 0;
	cin >> h >> w >> k;
	for(int i = 0; i < h; i++) {
		cin >> c[i];
	}
	for(int row = 0; row < (1 << h); row++) {
		for(int col = 0; col < (1 << w); col++) {
			int black = 0;
			for(int i = 0; i < h; i++) {
				for(int j = 0; j < w; j++) {
					if(!((row >> i) & 1) && !((col >> j) & 1)
					   && c[i][j] == '#') {
						black++;
					}
				}
			}
			if(black == k) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}