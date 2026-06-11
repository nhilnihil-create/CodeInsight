#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
using namespace std;
int main(){
	ll n,k,a[305];
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	ll dp[305][305];
	for(ll i=1;i<=300;i++){
		for(ll j=1;j<=i;j++)dp[i][j]=10000000000000000;
	}
	dp[0][0]=0;
	for(ll i=1;i<=n;i++)dp[i][1]=a[i];
	for(ll i=2;i<=n;i++){
		for(ll j=2;j<=i;j++){
			for(ll k=j-1;k<i;k++){
				if(a[k]<a[i]){
					dp[i][j]=min(dp[i][j],dp[k][j-1]+a[i]-a[k]);
				}else {
					dp[i][j]=min(dp[i][j],dp[k][j-1]);
				}
			}
		}
	}
	ll ans=10000000000000000;
	for(ll i=n-k;i<=n;i++){
		ans=min(ans,dp[i][n-k]);
	}
	cout<<ans;
	return 0;
}
