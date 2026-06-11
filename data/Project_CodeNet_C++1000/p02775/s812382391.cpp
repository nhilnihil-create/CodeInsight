#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 1e6+1;
string s;
int dp[A][2];
int solve(int ind, bool rem)
{
	if (ind == (int)s.size())
		return rem;
	if (~dp[ind][rem])
		return dp[ind][rem];

	int ret = 2e9;
	if (s[ind] != '9') ret = solve(ind + 1, 1) + rem + 1 + (s[ind] - '0');

	ret = min(ret, solve(ind + 1, 0) + rem + (s[ind] - '0'));

	ret = min(ret, solve(ind + 1, 0) + (rem ? 0 : 1) + (10 - (s[ind] - '0')));

	ret = min(ret, solve(ind + 1, 1) + (rem ? 0 : 1) + (9 - (s[ind] - '0')));

	return dp[ind][rem] = ret;
}
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> s;
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0);
	return 0;
}
