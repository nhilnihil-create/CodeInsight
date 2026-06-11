#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dp[1000010][2];
int main() {
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	ll ans=INF;
	for(ll i=0;i<1000010;i++){
		for(ll j=0;j<2;j++){
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(ll i=0;i<s.size();i++){
		ll now=s[i]-'0';
		dp[i+1][0]=min(dp[i+1][0],dp[i][0]+now);
		dp[i+1][1]=min(dp[i+1][1],dp[i][0]+10-now);
		dp[i+1][0]=min(dp[i+1][0],dp[i][1]+now+1);
		dp[i+1][1]=min(dp[i+1][1],dp[i][1]+10-(now+1));
		if(i==s.size()-1){
		ans=min(ans,dp[i+1][0]);
		ans=min(ans,dp[i+1][1]+1);
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}