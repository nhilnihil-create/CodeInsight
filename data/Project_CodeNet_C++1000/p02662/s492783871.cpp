#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,s,mod=998244353,a[3005],dp[3005][3005];
int main(){
	n=read(),s=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=s;j++){
			dp[i+1][j]+=2*dp[i][j];
			dp[i+1][j]%=mod;
			if(j+a[i]<=s){
				dp[i+1][j+a[i]]+=dp[i][j];
				dp[i+1][j+a[i]]%=mod;
			}
		}
	cout << dp[n][s];
	return 0;
}