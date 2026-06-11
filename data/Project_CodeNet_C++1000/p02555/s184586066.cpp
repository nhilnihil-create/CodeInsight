#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main()
{
	int s;
	cin>>s;
	ll dp[2010];
	dp[3]=1;
	for(int i=4;i<2010;i++)
	{
		dp[i]=(dp[i-1]+dp[i-3])%mod;
	}
	cout<<dp[s]<<endl;
	return 0;
}