#include<bits/stdc++.h>
using namespace std;
bool dp[1100000];
int main()
{
	dp[0]=1;
	for(int i=1;i<=1000100;i++){
		if(i<100)continue;
		if(dp[i-100]==1)dp[i]=1;
		if(i<101)continue;
		if(dp[i-101]==1)dp[i]=1;
		if(i<102)continue;
		if(dp[i-102]==1)dp[i]=1;
		if(i<103)continue;
		if(dp[i-103]==1)dp[i]=1;
		if(i<104)continue;
		if(dp[i-104]==1)dp[i]=1;
		if(i<105)continue;
		if(dp[i-105]==1)dp[i]=1;
	}
	int x;cin>>x;
	cout<<dp[x];
	return 0;
}