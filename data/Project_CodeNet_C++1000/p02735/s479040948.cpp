#include<bits/stdc++.h>
using namespace std;

char s[101][101];

int dp[101][101];

int main()
{
	int H, W;
	scanf("%d%d", &H, &W);
	for(int i = 1; i <= H; i++)
		scanf("%s", s[i] + 1);
	dp[1][1] = (s[1][1] == '#');
	for(int i = 1; i <= H; i++)
	{
		for(int j = 1; j <= W; j++)
		{
			if(i == 1 && j == 1)
				continue;
			if(i == 1)
				dp[i][j] = dp[i][j-1] + (s[i][j-1] == '.' && s[i][j] == '#');
			else if(j == 1)
				dp[i][j] = dp[i-1][j] + (s[i-1][j] == '.' && s[i][j] == '#');
			else
				dp[i][j] = min(dp[i][j-1] + (s[i][j-1] == '.' && s[i][j] == '#'), dp[i-1][j] + (s[i-1][j] == '.' && s[i][j] == '#'));
		}
	}
	printf("%d\n", dp[H][W]);
	return 0;
}