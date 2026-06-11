#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1100000000;
const int H_MAX = 10000;
const int N_MAX = 1000;

int main() {
	int h, n;
	cin >> h >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	int dp[H_MAX+1];
	dp[0] = 0; fill(dp+1, dp+H_MAX+1, INF);
	for (int j = 1; j <= h; j++) {
		for (int i = 0; i < n; i++) {
			dp[j] = min(dp[j], b[i]+dp[max(0, j-a[i])]);
		}
	}
	int ans = dp[h];
	cout << ans << endl;
	return 0;
}