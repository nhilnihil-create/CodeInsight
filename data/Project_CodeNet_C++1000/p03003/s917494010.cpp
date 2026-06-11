#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;
const int maxn=2e3+5;
typedef long long ll;
const int mod=1e9+7;

int main()
{
  ll dp[maxn][maxn],sum[maxn][maxn];
  int n,m;
  int s[maxn],t[maxn];
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin >> t[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i]==t[j]) dp[i][j]=sum[i-1][j-1]+1;
			else dp[i][j]=0;
      dp[i][j] %= mod;
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+dp[i][j];
			sum[i][j] %= mod;
		}
	}
	sum[n][m]++;
  sum[n][m] %=mod;
  sum[n][m] += 2ll*mod;
  sum[n][m] %=mod;
	cout << sum[n][m] << endl;
  return 0;
}
