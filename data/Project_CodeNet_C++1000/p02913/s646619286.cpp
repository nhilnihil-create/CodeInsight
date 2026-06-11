#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dp[5002][5002];
int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(i==j){
				continue;
			}
			if(s[i]==s[j]){
				if(i==0||j==0){
					dp[i][j]=1;
				}
				else{
				dp[i][j]=dp[i-1][j-1]+1;
				}
			}
			if(i<j){
				if(i+dp[i][j]>j){
					continue;
				}
			}
			if(j<i){
				if(j+dp[i][j]>i){
					continue;
				}
			}
			ans=max(ans,dp[i][j]);
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}