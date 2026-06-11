#include <vector>
#include <iostream>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int main() {

	int n, x, y; cin >> n >> x >> y;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	vector<int> ans(n, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) dp[i][j] = min({abs(i - j), abs(x - i) + 1 + abs(j - y), abs(x - j) + 1 + abs(i - y)}), ans[dp[i][j]]++;
	}

	for (int k = 1; k <= n - 1; k++) cout << ans[k] << "\n";

	return 0;
}