#include <bits/stdc++.h>
using namespace std;
string arr;
int mod = 1e9+7;
vector<vector<int>>dp;
long long getsum(int n,long long sum,int ind)
{
	if(ind>n)return (sum==5);

	if(dp[ind][sum]!=-1)return dp[ind][sum];
	long long res=0;
	
		if(arr[ind]=='?')
		{
			for(int i=0;i<=9;i++)
			{
		     	res = (res+getsum(n,((sum*10)%13+i)%13,ind+1)%mod)%mod;
			}
		}
			else res = (res+getsum(n,((sum*10)%13+arr[ind]-'0')%13,ind+1)%mod)%mod;
	
	return dp[ind][sum]=res;
}
int main() {
	// your code goes here
	cin.tie(NULL);
	cout.tie(NULL);
        cin>>arr;
		int k=arr.size();
		dp = vector<vector<int>>(100005,vector<int>(200,-1));
		// memset(dp,-1,sizeof(dp));
		long res = (getsum(k-1,0,0))%mod;
		cout<<res<<endl;
	
	return 0;
}