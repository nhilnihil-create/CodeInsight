#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[15][114514];
int main(){
	string s;
	cin>>s;
	ll n=s.size();
	if(s[n-1]=='?')for(int i=0;i<=9;i++)dp[i][1]++;
	else dp[(s[n-1]-'0')][1]++;
	ll mod=1e9+7,now=1;
	for(int i=n-2;i>=0;i--){
		now*=10;
		now%=13;
		if(s[i]=='?'){
			for(int j=0;j<=9;j++){
				 ll x=j*now%13;
				 for(int k=0;k<=12;k++){
					 dp[k][n-i]+=dp[(13+k-x)%13][n-i-1];
					 dp[k][n-i]%=mod;
				 }
			}
		}else{
			ll x=s[i]-'0';
			x=x*now%13;
			for(int k=0;k<=12;k++){
				dp[k][n-i]+=dp[(13+k-x)%13][n-i-1];
				dp[k][n-i]%=mod;
			}
		}
	}
	cout<<dp[5][n]<<endl;
	return 0;
}
