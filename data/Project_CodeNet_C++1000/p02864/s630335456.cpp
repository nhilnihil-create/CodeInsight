#include <bits/stdc++.h>
#define INF 1000000000000000
#define int long long

using namespace std;

int n=0,k=0;
int h[301];
int dp[301][301];

signed main()
{
	cin >> n >> k;
	for (int i=0; i<n; i++)
	{
		cin >> h[i];		
	}
	if (k==n)
	{
		cout << 0;
		return 0;
	}
	for (int j=0; j<n; j++)
	{
		dp[1][j] = h[j];	
	}
	for (int i=2; i<=n-k; i++)
		for (int j=0; j<n; j++)
			dp[i][j] = INF;
	for (int i=2; i<=n-k; i++)
	{
		for (int j=0; j<n; j++)
		{
			for (int k=j+1; k<n; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i-1][k]+max(0ll, h[k]-h[j])+h[j]-h[k]);	
			}	
		}		
	}
	int Min = INF;		
	/*for (int i=1; i<=n-k; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << dp[i][j] << ' ';	
		}
		cout << endl;
	}
	cout << endl;*/
	for (int j=0; j<n; j++)
	{
		Min = min(Min, dp[n-k][j]);
	}
	cout << Min;
	return 0;
}
