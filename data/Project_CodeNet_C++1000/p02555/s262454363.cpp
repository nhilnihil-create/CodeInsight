#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main() {
	int s;
	cin >> s;
	int ans = 0;
	vector<vector<int>> c(s + 1, vector<int>(s + 1, 1));
	for (int i = 1; i <= s; ++i) {
		for (int j = 1; j < i; ++j) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			c[i][j] %= mod;
		}
	}
	for (int i = 1; i < s; ++i) {
		if (s - i * 3 < 0) break;
		ans += c[s - i * 3 + i - 1][i - 1];
		ans %= mod;
	}
	cout << ans;
}