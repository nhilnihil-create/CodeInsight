#include <bits/stdc++.h>
using namespace std;
 
 
static const int INF = 10000007;
 
int main()
{
	int h, w;
	int ma[101][101];
	cin >> h >> w;
	string in;
	for (int i = 1; i <= h; ++i)
	{
		cin >> in;
		for (int j = 1; j <= w; ++j)
		{
			ma[i][j] = (in[j-1] == '#');
		}
	}
	int dp[101][101] = {};
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			dp[i][j] = INF;
		}
	}
 
	dp[1][0] = dp[0][1] = 0;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			dp[i][j] = min((ma[i-1][j]==0&&ma[i][j]?1:0) + dp[i-1][j], (ma[i][j-1]==0&&ma[i][j]?1:0) + dp[i][j-1]);
		}
	}
	cout << dp[h][w] << endl;
	return 0;
}