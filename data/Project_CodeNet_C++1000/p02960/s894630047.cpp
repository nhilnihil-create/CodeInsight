#include <bits/stdc++.h>
using namespace std;
string arr;
long long mod=1e9+7;
int dp[100001][30];
long long getsum(int ind,int sum){
	if(ind==arr.size()) return (sum%13==5?1:0);
	if(dp[ind][sum]!=-1) return dp[ind][sum];
	int limit=9;
	
	long long res=0;
	
	
		if(arr[ind]=='?'){
			for(int i=0;i<=limit;i++){
			res+=getsum(ind+1,(sum*10+i)%13);
			res%=mod;
			
		        }
		}
		else res+=getsum(ind+1,(sum*10+(arr[ind]-'0'))%13), res%=mod;
	return dp[ind][sum]=res;;
}
int main() {

    cin>>arr;
    memset(dp,-1,sizeof(dp));
    cout<<getsum(0,0)<<endl;

	return 0;
}