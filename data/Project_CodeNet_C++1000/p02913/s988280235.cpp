#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll dp[5001][5001];
int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(s[i]==s[j]){
				if(i+dp[i][j]!=j){
					dp[i+1][j+1]=dp[i][j]+1;
					ans=max(dp[i+1][j+1],ans);
				}
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}