#include <iostream>

using namespace std;
static const int NINF = -100;
int dp[17][17];

void solve()
{
	int a, b;
	while(cin >> a >> b, a || b)
	{
		int n;
		cin >> n;
		for(int i = 0; i < b; ++i)
		{
			for(int j = 0; j < a; ++j)
			{
				dp[i][j] = NINF;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			x--; y--;
			dp[y][x] = 0;
		}
		for(int i = 0; i < a; ++i)
		{
			if(dp[0][i] != 0)
			{
				dp[0][i] = 1;
			}
			else
			{
				for(int j = i; j < a; ++j)
				{
					dp[0][j] = 0;
				}
				break;
			}
		}
		for(int i = 0; i < b; ++i)
		{
			if(dp[i][0] != 0)
			{
				dp[i][0] = 1;
			}
			else
			{
				for(int j = i; j < a; ++j)
				{
					dp[j][0] = 0;
				}
				break;
			}
		}
		for(int i = 1; i < b; ++i)
		{
			for(int j = 1; j < a; ++j)
			{
				if(dp[i][j] != 0)
				{
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
				}
			}
		}
		cout << dp[b - 1][a - 1] << endl;
	}
}

int main()
{
	solve();
	return(0);
}