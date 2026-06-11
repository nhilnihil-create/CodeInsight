#include <bits/stdc++.h>
using namespace std;
string s;
int mod = 1e9+7,n;
vector<vector<int> > dp(1e5,vector<int>(13,-1));
 
int digit_dp(int idx,int sum){
	if(idx==n)
		return sum==5?1:0;
	if(s[idx]!='?')
		return dp[idx][sum] = digit_dp(idx+1,(sum*10+s[idx]-48)%13);
	if(dp[idx][sum]==-1){
		dp[idx][sum]++;
		for(int i=0;i<10;i++)
			dp[idx][sum] = (dp[idx][sum]+digit_dp(idx+1,(sum*10+i)%13))%mod;
	}
	return dp[idx][sum];
}
 
int main()
{
    cin >> s;
    n = s.size();
    cout << digit_dp(0,0);
    return 0;
}