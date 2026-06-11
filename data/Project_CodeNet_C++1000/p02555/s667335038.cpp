#include <bits/stdc++.h>
using namespace std;
typedef  long long  ll;
	int mod=1e9+7;
	int dp[2000+4];
	int main() {

		#ifndef ONLINE_JUDGE
	        freopen("input.txt","r",stdin);
	        // freopen("output.txt","w",stdout);
	    #endif
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
	   	
	   	int s;
	 	cin>>s;
	

	 	vector<int> dp(s+1,0);
		dp[0]=1;

	  	for(int sum=3; sum<=s; sum++){
	  		for(int i=3;i<=sum;i++){
	  			dp[sum]+=dp[sum-i];
	  			dp[sum]%=mod;
	  		}
	  	}
	  	cout<<dp[s]<<endl;
	    return 0;
}