#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long dp[2005];
long long f(int sum){
	if(sum<0) return 0;
	long long&ret = dp[sum];
	if(~ret) return ret;
	ret = 0;
	for(int i=3; i<=sum; i++) ret+=f(sum-i);
	return ret%=mod;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int s;
	cin>>s;
	dp[0] = 1;
	cout<<f(s);
}