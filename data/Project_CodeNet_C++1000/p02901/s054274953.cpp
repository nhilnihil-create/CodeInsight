#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1 << 12;
const int INF = 1001001001;

int main() {
	int n, m;
	cin >> n >> m;
	int dp[MAX]; fill(dp, dp+MAX, INF);
	dp[0] = 0;
	for (int j = 1; j <= m; j++) {
		int a, b, c = 0;
		cin >> a >> b;
		for (int k = 0; k < b; k++) {
			int x;
			cin >> x;
			x--;
			c |= (1 << x);
		}
		for (int i = (1<<n)-1; i > 0; i--) {
			dp[i] = min(dp[i], a + dp[i&(~c)]);
		}
	}
	int ans = dp[(1<<n) - 1];
	if (ans >= INF) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}