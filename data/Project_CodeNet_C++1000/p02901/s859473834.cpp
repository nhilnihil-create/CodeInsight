#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dp[4200];
int main() {
	for(ll i=0;i<4200;i++){
		dp[i]=INF;
	}
	dp[0]=0;
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		ll op=0;
		for(ll j=0;j<y;j++){
			ll now;
			cin>>now;
			now--;
			now=pow(2,now);
			op=op|now;
		}
		for(ll j=0;j<4200;j++){
			if(ll(j|op)<4200){
			dp[j|op]=min(dp[j]+x,dp[j|op]);
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
	  ans=ans|ll(pow(2,i));
	}
//	cout <<ans<<endl;
if(dp[ans]==INF){
	cout << -1;
	return 0;
}
	cout <<dp[ans];
	// your code goes here
	return 0;
}