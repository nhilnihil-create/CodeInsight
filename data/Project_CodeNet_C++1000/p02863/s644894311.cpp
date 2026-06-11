#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n, t; cin >> n >> t;
	vector<int> a(n), b(n);
	rep(i, n)cin >> a[i] >> b[i];
	vector<vector<int>> dp(n + 1, vector<int>(t)), rdp(n + 1, vector<int>(t));
	rep(i, n)rep(j, t)
	{
		if (j + a[i] < t)dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + b[i]);
		dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
	}
	rrep(i, n)rep(j, t)
	{
		if (j + a[i] < t)rdp[i][j + a[i]] = max(rdp[i][j + a[i]], rdp[i + 1][j] + b[i]);
		rdp[i][j] = max(rdp[i][j], rdp[i + 1][j]);
	}
	int res = 0;
	rep(i, n)
	{
		int tmp = 0;
		rep(j, t)
		{
			tmp = max(tmp, dp[i][j] + rdp[i + 1][t - 1 - j]);
		}
		res = max(res, tmp + b[i]);
	}
	cout << res << endl;
}