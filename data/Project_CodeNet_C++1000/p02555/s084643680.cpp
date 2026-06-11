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
	   	

	   	int x;
	   	cin>>x;
	   	
	   	dp[0]=1;
	  	for(int sum=0; sum<=x; sum++){
	  		for(int coin =3;coin<=sum;coin++){
	  			dp[sum]+=dp[sum-coin];
	  			dp[sum]%=mod;
	  		}
	  	}
	  	cout<<dp[x]<<endl;
	    return 0;
}



	

