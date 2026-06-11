#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h, w; cin >> h >> w;
	vector<vector<char>> c(h + 2, vector<char>(w + 2, 'e'));
	for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin >> c[i][j];

	vector<vector<int>> L(h + 2, vector<int>(w + 2, 0));
	vector<vector<int>> R(h + 2, vector<int>(w + 2, 0));
	vector<vector<int>> U(h + 2, vector<int>(w + 2, 0));
	vector<vector<int>> D(h + 2, vector<int>(w + 2, 0));

	for (int i = 1; i <= h; i++) {
		int now_x = 0;
		for (int j = 1; j <= w; j++) {						
			if (c[i][j] == '#') now_x = 0;			
			else now_x++;
			L[i][j] = now_x;
		}
	}
	for (int i = 1; i <= h; i++) {
		int now_x = 0;
		for (int j = w; j >= 0; j--) {
			if (c[i][j] == '#') now_x = 0;
			else now_x++;
			R[i][j] = now_x;
		}
	}

	for (int j = 1; j <= w; j++) {
		int now_y = 0;
		for (int i = 1; i <= h; i++) {
			if (c[i][j] == '#') now_y = 0;
			else now_y++;
			D[i][j] = now_y;
		}
	}
	for (int j = 1; j <= w; j++) {
		int now_y = 0;
		for (int i = h; i >= 0; i--) {
			if (c[i][j] == '#') now_y = 0;
			else now_y++;
			U[i][j] = now_y;
		}
	}

	int  ans = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (c[i][j] == '#') continue;
			int tmpAns = max(1, L[i][j] + R[i][j] + D[i][j] + U[i][j] - 3);
			ans = max(ans, tmpAns);
		}
	}
	cout << ans << endl;
	return 0;
}