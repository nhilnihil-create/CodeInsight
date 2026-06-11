#include <bits/stdc++.h>
#define sort stable_sort 
using namespace std;

int _;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod=1e9+7;

int n;
long long dp[1000500][2][2];


int main()
{	
	//for(scanf("%d",&_);_;_--)
	scanf("%d",&n);
	dp[0][0][0]=1;
	for(int i=1;i <= n;i++)
	{
		dp[i][0][0]=(dp[i-1][0][0] << 3)%mod;
		dp[i][1][0]=(dp[i-1][1][0]*9+dp[i-1][0][0])%mod;
		dp[i][0][1]=(dp[i-1][0][1]*9+dp[i-1][0][0])%mod;
		dp[i][1][1]=(dp[i-1][1][0]+dp[i-1][0][1]+dp[i-1][1][1]*10)%mod;
	}
	printf("%lld\n",dp[n][1][1]%mod);
	return 0;
}   	         