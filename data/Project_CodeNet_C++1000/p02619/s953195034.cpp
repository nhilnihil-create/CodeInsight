#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int D;
vector<int> c(30, 0);
vector<vector<int>> s(400, vector<int>(30, 0));
vector<vector<int>> last(400, vector<int>(30, 0));
vector<int> t(400, 0), ans_B(400, 0);

void input() {
	cin >> D;
	for (int i = 1; i <= 26; ++i) { cin >> c[i]; }
	for (int i = 1; i <= D; ++i) {
		for (int j = 1; j <= 26; ++j) { cin >> s[i][j]; }
	}
	for (int i = 1; i <= D; ++i) { cin >> t[i]; }
}

void calc_score() {
	for (int d = 1; d <= D; ++d) {
		for (int i = 1; i <= 26; ++i) { last[d][i] = last[d - 1][i]; }
		last[d][t[d]] = d;

		ans_B[d] = s[d][t[d]] + ans_B[d - 1];
		for (int i = 1; i <= 26; ++i) {
			ans_B[d] -= c[i] * (d - last[d][i]);
		}
	}
}

int main() {
	input();
	calc_score();
	for (int i = 1; i <= D; ++i) {
		cout << ans_B[i] << endl;
	}

	return 0;
}
