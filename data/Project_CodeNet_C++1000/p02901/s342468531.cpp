
// E - Get Everything

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N, M;

int dp[4096]; // dp[bit]: 開いた宝箱の状態がbitの時のコストの最小値
int cost[1000];
int can_open[1000];

int main() {
	cin >> N >> M;

	int a, b;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		cost[i] = a;
		int c;
		for (int j=0; j<b; j++) {
			cin >> c;
			c--;
			can_open[i] |= (1<<c);
		}
	}

	fill(dp, dp+4096, INF);
	dp[0] = 0;
	for (int i=0; i<M; i++) {
		for (int bit = 0; bit <= (1<<N) - 1; bit++) {
			if (dp[bit] == INF) continue;
			dp[bit | can_open[i]] = min(dp[bit | can_open[i]], dp[bit] + cost[i]);
		}
	}

	int ans;
	if (dp[(1<<N) - 1] == INF) {
		ans = -1;
	} else {
		ans = dp[(1<<N) - 1];
	}

	cout << ans << endl;

	return 0;
}