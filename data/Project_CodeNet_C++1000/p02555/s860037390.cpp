#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m=1e9+7;
ll s,dp[2005];
int main()
{
	cin>>s;
	dp[3]=1,dp[4]=1;
	ll now=2;
	for(int i=5;i<=s;i++)
	{
		dp[i]=(1+now-dp[i-1]-dp[i-2])%m;
		now+=dp[i];
	}
	cout<<dp[s]%m<<endl;
}