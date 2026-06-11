#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, m, i, j, k, ans, ss, MOD = 1000000007LL;
	cin >> n >> m;
	vector<long long> s(n + 1), t(m + 1);
	for (i = 1; i <= n; i++) cin >> s[i];
	for (i = 1; i <= m; i++) cin >> t[i];

	vector<vector<long long >> dp(n + 1, vector<long long>(m + 1, 0));
	vector<vector<long long >> sum(n + 1, vector<long long>(m + 1, 0));
	ans = 1;
	sum[0].assign(m + 1, 1);
	for (i = 1; i <= n; i++) sum[i][0] = 1;
	for (i = 1; i <= n; i++) {
		ss = 0;
		for (j = 1; j <= m; j++) {
			if (s[i] == t[j]) {
				dp[i][j] = sum[i - 1][j - 1];
				ans = (ans + sum[i - 1][j - 1]) % MOD;
			}
			ss += dp[i][j];
			sum[i][j] = (sum[i - 1][j] + ss) % MOD;
		}
	}

	cout << ans % MOD << "\n";

	return 0;
}
