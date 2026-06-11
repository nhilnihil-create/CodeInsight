#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int ll

const int INF = 2e15;

signed main ()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int h, n;
	cin >> h >> n;

	vector <int> dp(h + 1, INF);
	dp[0] = 0;

	while (n--) {
		int value, cost;
		cin >> value >> cost;

		for (int i = 0; i <= h; i++) {
			int j = min(i + value, h);
			dp[j] = min(dp[j], dp[i] + cost);
		}
	}

	cout << dp[h] << endl;

	return 0;
}
