#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1100000000;
const int H_MAX = 10000;
const int N_MAX = 1000;

int main() {
	int h, n;
	cin >> h >> n;
	int dp[N_MAX+1][H_MAX+1];
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int j = 1; j <= h; j++) dp[0][j] = INF;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 1; j <= h; j++) {
			int v1 = dp[i-1][j];
			int v2 = b + dp[i-1][max(0, j-a)];
			int v3 = b + dp[i][max(0, j-a)];
			dp[i][j] = min({v1, v2, v3});
		}
	}
	int ans = dp[n][h];
	cout << ans << endl;
	return 0;
}