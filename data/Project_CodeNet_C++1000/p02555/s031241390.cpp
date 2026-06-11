#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define M 1010
#define N 1000000
#define D double
#define LL long long
using namespace std;
LL n,dp[N],mod=1e9+7;
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	dp[3]=1;
	for(int i=4;i<=n;i++) dp[i]=(dp[i-1]+dp[i-3])%mod;
	cout<<dp[n];
	return 0;
}
/*
*/
