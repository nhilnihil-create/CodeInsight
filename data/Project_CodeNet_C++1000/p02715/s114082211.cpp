// stay fuckin hard -- Abhinav -IIITA
#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
int mod=1e9+7;
ld pi=3.1415926535;
int fun(int a,int b){
	int r=1;
	while(b>0){
		if(b&1){
			r*=a;
			r%=mod;
		}
		b/=2;
		a*=a; a%=mod;
	}
	return r;
}
int32_t main(){
	int n,k; cin>>n>>k;
	int ans=0;
	int dp[k+1]={0};
	for(int i=k;i>0;--i){
		dp[i]=fun((k/i),n);
		for(int ii=2*i;ii<=k;ii+=i){
			dp[i]-=dp[ii]; dp[i]+=mod; dp[i]%=mod;
		}
		dp[i]+=mod; dp[i]%=mod;
		ans+=(i*dp[i])%mod; ans+=mod; ans%=mod;
	}
	cout<<ans;
	return 0;
}
