//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;
const int M    = 1e9 + 7;

ll vis[N];
ll dp[N];
int  main(){
	
	ll n,m;
	cin>>n>>m;
	ll x;

	while(m--){
		cin>>x;
		vis[x] = 1LL;
	}
	if(vis[0] == 0)dp[0] = 1LL;
	if(vis[1] == 0)dp[1] = 1LL;

	for(ll i=2;i<=n;i++){
		if(vis[i])continue;
		dp[i] = (dp[i]+dp[i-1])%M;
		dp[i] = (dp[i]+dp[i-2])%M;
	}
	
	cout<<dp[n]%M<<endl;
	return 0;
}