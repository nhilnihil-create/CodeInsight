#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll dp[100010][13];
int main() {
	string s;
	cin>>s;
	if(s[0]=='?'){
	for(ll i=0;i<10;i++){
		dp[0][i]=1;
	}
	}
	else{
		dp[0][s[0]-'0']=1;
	}
	for(ll i=1;i<s.size();i++){
		for(ll j=0;j<13;j++){
			if(s[i]=='?'){
			for(ll k=0;k<=9;k++){
				ll now=k+j*10;
				now%=13;
				dp[i][now]+=dp[i-1][j];
				dp[i][now]%=inf;
			}
			}
			else{
				ll now=s[i]-'0'+j*10;
				now%=13;
				dp[i][now]+=dp[i-1][j];
				dp[i][now]%=inf;
			}
		}
	}
	cout << dp[s.size()-1][5];
	// your code goes here
	return 0;
}