#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	vector<vector<int>> c_next(s.size() + 1 /*最後は-1*/, vector<int>(26, -1));
	vector<vector<int>> c_pos(26, vector<int>());

	{
		// 最初だけ別処理
		int i = s.size() - 1;
		c_next[i][s[i] - 'a'] = i;

		for (int i = s.size() - 2; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				if (s[i] == 'a' + j) {
					c_next[i][j] = i;
				} else {
					c_next[i][j] = c_next[i + 1][j];
				}
			}
		}
	}
	/*c_nextの表示
	for (int j = 0; j < 26; j++) {
	    printf(" %c ", j + 'a');
	}
	printf("\n");
	for (int i = 0; i < s.size(); i++) {
	    for (int j = 0; j < 26; j++) {
	        printf("%2d ", c_next[i][j]);
	    }
	    printf("\n");
	}
	*/

	long long x = 0, y = 0;
	for (int i = 0; i < t.size(); i++) {
		if (c_next[0][t[i] - 'a'] == -1) {
			cout << "-1";
			return 0;
		}
		if (c_next[y][t[i] - 'a'] != -1) {
			y = c_next[y][t[i] - 'a'] + 1;
		} else {
			y = c_next[0][t[i] - 'a'] + 1;
			x++;
		}
		// cout << t[i] << " " << x << " " << y << "\n";
	}

	// cout << x << "回ループ後の " << y - 1 << "文字目(0始まり)\n";

	cout << x * s.size() + y;
	return 0;
}