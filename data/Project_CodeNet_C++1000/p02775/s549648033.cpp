#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	s.push_back('0');
	ll dp[1000010][2];
	for(ll i=0;i<1000010;i++){
		for(ll j=0;j<2;j++){
			dp[i][j]=inf;
		}
	}
	dp[0][0]=0;
	for(ll i=0;i<s.size();i++){
		ll now=s[i]-'0';
		//cout<<now<<endl;
		for(ll j=0;j<2;j++){
			now=now+j;
			for(ll k=0;k<10;k++){
				if(k>=now){
					dp[i+1][0]=min(dp[i+1][0],dp[i][j]+k+k-now);
				}
				else{
					dp[i+1][1]=min(dp[i+1][1],dp[i][j]+k+k-now+10);					
				}
			}
		}
	}
	cout << dp[s.size()][0];
	// your code goes here
	return 0;
}