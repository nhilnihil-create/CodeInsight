#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int MAXN = 1e4;
const int INF = 1e9;

int dp[N];
int val[N], cost[N];

int main() {
	int h, n; cin >> h >> n;
	for (int i = 0; i < n; i++)
		cin >> val[i] >> cost[i];
	fill(dp, dp + N, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = val[i]; j <= MAXN; j++)
			dp[j] = min(dp[j], dp[j - val[i]] + cost[i]);
	cout << *min_element(dp + h, dp + N);
}