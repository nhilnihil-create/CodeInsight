#include<bits/stdc++.h>

#define ll long long 
#define mod 1000000007

using namespace std;

int main(){
	ll S;
	cin>>S;

	vector<ll> dp(S+1, 0);

	for(ll i=3; i<=S; i++){
		dp[i] = 1;
		for(int j = 3; j<=(i-3); j++){
			// if(j!=(i-j)){
				dp[i] = (dp[i] + dp[i-j])%mod;
				// cout<<dp[i]<<endl;
			// }
			// else{
			// 	dp[i]+=dp[i-j];
			// }
		}
	}

	cout<<dp[S];

	return 0;
}