#include <bits/stdc++.h>
using namespace std;
using vi    = vector<int>;
constexpr int    MOD=1e9+7;

int main(){//Refering other editorials.
	int s;
	cin>>s;
	
	vi dp(s+1,0);
	dp[0]=1;
	for(int i=3;i<=s;++i) dp[i]=(dp[i-3]+dp[i-1])%MOD;
	
	cout<<dp[s]<<endl;
	return 0;
}