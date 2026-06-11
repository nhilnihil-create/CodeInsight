#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	for (int i = 0; i < h; i++) cin >> grid[i];
	int a[h][w], b[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			a[i][j] = grid[i][j]=='.' ? 1 : -1;
			b[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w-1; j++) {
			if (a[i][j] != -1 && a[i][j+1] != -1) a[i][j+1] += a[i][j];
		}
		for (int j = w-1; j > 0; j--) {
			if (a[i][j] != -1 && a[i][j-1] != -1) a[i][j-1] = a[i][j];
		}
	}
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h-1; i++) {
			if (b[i][j] != -1 && b[i+1][j] != -1) b[i+1][j] += b[i][j];
		}
		for (int i = h-1; i > 0; i--) {
			if (b[i][j] != -1 && b[i-1][j] != -1) b[i-1][j] = b[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ans = max(ans, a[i][j]+b[i][j]-1);
		}
	}
	cout << ans << endl;
	return 0;
}