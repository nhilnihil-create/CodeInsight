#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	int n,h;
	cin>>h>>n;
	int a[n],b[n],maxi=0;
	rep(i,n){
		cin>>a[i]>>b[i];
		maxi = max(a[i],maxi);
	}
	
	int dp[h+maxi+1];
	rep(i,h+maxi+1)dp[i]=mod;
	dp[0]=0;
	rep(i,h){
		rep(j,n){
			dp[i+a[j]] = min(dp[i]+b[j],dp[i+a[j]]);
		}
	}

	int ans=mod;
	for(int i=h;i<h+maxi+1;i++){
		ans=min(ans,dp[i]);
	}

	cout<<ans<<endl;

	return 0;
}
