#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

#define int long long

int n,k;
int a[311];
int f[311][311];

int dp(int pos,int cur)
{
	if (pos >= n+1)
	{
		if (cur >= n-k)
			return 0;
		return 1e18;
	}	
	if (f[pos][cur] != -1)
		return f[pos][cur];
	int z = 1e18;
	z = min(z,dp(n+1,cur));
	for (int j=pos+1;j<=n;j++)
		z = min(z,dp(j,cur+1) + max(0LL,a[j] - a[pos]));		
	return f[pos][cur] = z;	
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for (int i=0;i<=300;i++)
		for (int j=0;j<=300;j++)
			f[i][j] = -1;
	cout << dp(0,0);
}       	