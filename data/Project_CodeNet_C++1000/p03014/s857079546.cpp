#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> pre1(n, vector<int>(m)), pre2(m, vector<int>(n)), suf1(n, vector<int>(m)), suf2(m, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#') {
				pre1[i][j] = 0;
			} else {
				pre1[i][j] = (j == 0 ? 1 : pre1[i][j - 1] + 1);
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i][j] == '#') {
				pre2[j][i] = 0; 
			} else {
				pre2[j][i] = (i == 0 ? 1 : pre2[j][i - 1] + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			if (a[i][j] == '#') {
				suf1[i][j] = 0;
			} else {
				suf1[i][j] = (j == m - 1 ? 1 : suf1[i][j + 1] + 1);
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j] == '#') {
				suf2[j][i] = 0; 
			} else {
				suf2[j][i] = (i == n - 1 ? 1 : suf2[j][i + 1] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, pre1[i][j] + pre2[j][i] + suf1[i][j] + suf2[j][i]);
			//cout << i << " " << j << " " << pre1[i][j] + pre2[j][i] + suf1[i][j] + suf2[j][i] << '\n';
		}
	}
	cout << ans - 3 << '\n';
}
