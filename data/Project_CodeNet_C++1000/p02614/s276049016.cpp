#include <iostream>
#include<vector>
#include <string>
using namespace std;





int ncm(int n, int m) {
	double ans = 1;
	for (int i = 0; i < m; i++) {
		ans = ans * ((double)n - (double)i) / ((double)m - (double)i);
	}
	return (int)ans;
}

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	int c[6][6];
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char a;
			cin >> a;
			if (a == '.') c[i][j] = 0;
			else c[i][j] = 1;
		}
	}

	for (int tatebit = 0; tatebit < (1 << h); tatebit++) {
		for (int yokobit = 0; yokobit< (1 << w);yokobit++){
			int sum = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (tatebit & (1 << i)) {
						if (yokobit & (1 << j)) {
							sum += c[i][j];
						}
					}
				}
			}
			if (sum == k) ans++;
		}
	}
	cout << ans;
	return 0;
}