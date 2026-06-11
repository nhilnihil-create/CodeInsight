#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	int n; cin >> n;
	ll ans = 0;
	vector<vector<int>> dp(10, vector<int>(10, 0));
	for(int a = 1; a <= n; ++a)
	{
		string s = to_string(a);
		dp[s[0]-'0'][a%10]++;
	}
	for(int i = 1; i <= 9; ++i)
	{
		for(int j = 1; j <= 9; ++j)
		{
			ans += (dp[i][j] * dp[j][i]);
		}
	}
	cout << ans;
	return 0;
}