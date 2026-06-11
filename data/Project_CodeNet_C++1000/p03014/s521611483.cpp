#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w; cin >> h >> w;
	vector<vector<char>> c(h + 2, vector<char>(w + 2, 'e'));
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> c[i][j];
		}
	}
	vector<vector<int>> u(h + 2, vector<int>(w + 2, 0));
	vector<vector<int>> d(h + 2, vector<int>(w + 2, 0));
	vector<vector<int>> l(h + 2, vector<int>(w + 2, 0));
	vector<vector<int>> r(h + 2, vector<int>(w + 2, 0));
	for (int j = 1; j <= w; j++) {
		for (int i = h; i >= 1; i--) {
			if (c[i][j] == '.') u[i][j] += u[i + 1][j] + 1;
			else u[i][j] = 0;
		}
	}
	for (int j = 1; j <= w; j++) {
		for (int i = 1; i <= h; i++) {
			if (c[i][j] == '.') d[i][j] += d[i - 1][j] + 1;
			else d[i][j] = 0;
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = w; j >= 1; j--) {
			if (c[i][j] == '.') l[i][j] += l[i][j + 1] + 1;
			else l[i][j] = 0;
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {			
			if (c[i][j] == '.') r[i][j] += r[i][j - 1] + 1;
			else r[i][j] = 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (c[i][j] == '#') continue;
			int tmp = -3;
			tmp += u[i][j];
			tmp += d[i][j];
			tmp += l[i][j];
			tmp += r[i][j];
			tmp = max(0, tmp);
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}