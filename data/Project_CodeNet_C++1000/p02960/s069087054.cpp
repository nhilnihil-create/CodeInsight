#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
string s;
ll n;
ll mod=1e9+7;
ll dp[100001][13];
ll fun(ll i,ll r){
	if(i==n) return r==5;
	if(dp[i][r]!=-1) return dp[i][r];
	ll ans=0;
	if(s[i]!='?') ans=(ans+fun(i+1,(r*10+(s[i]-'0'))%13))%mod;
	else{
		for(int d=0;d<10;d++) ans=(ans+fun(i+1,(r*10+d)%13))%mod;
	}
	return dp[i][r]=ans;
}
int main(){
	cin>>s;
	memset(dp,-1,sizeof dp);
	n=s.size();
	cout<<fun(0,0);
}
