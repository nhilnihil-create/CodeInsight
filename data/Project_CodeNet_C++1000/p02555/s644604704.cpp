#include<bits/stdc++.h>
using namespace std;
long long dp[2001];
int main()
{
	int n;
	cin>>n;
	dp[3]=1;
	for(int i=4;i<=n;i++)
	dp[i]=(dp[i-1]+dp[i-3])%1000000007;
	cout<<dp[n]<<endl;
	return 0;
}