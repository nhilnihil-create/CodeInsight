#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+10;
int n,k,res,dp[N];
int qmi(int a,int b){
	int res=1;
	while(b){if(b&1LL) res=res*a%mod; a=a*a%mod; b>>=1LL;}
	return res;
}

signed main(){
	cin>>n>>k;
	for(int i=k;i>=1;i--){
		dp[i]=qmi(k/i,n);
		for(int j=i*2;j<=k;j+=i)	dp[i]=((dp[i]-dp[j])%mod+mod)%mod;
		res=(res+i*dp[i]%mod)%mod;
	}
	cout<<res;
	return 0;
}
