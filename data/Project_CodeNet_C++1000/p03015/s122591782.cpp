#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
ll dp[2][100010];
int main() {
	string s;
	cin>>s;
	dp[0][0]=1;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='1'){
			dp[0][i+1]+=2*dp[0][i];
			dp[1][i+1]+=3*dp[1][i]+dp[0][i];
		}
		if(s[i]=='0'){
			dp[0][i+1]+=dp[0][i];
			dp[1][i+1]+=3*dp[1][i];
		}
		dp[0][i+1]%=inf;
		dp[1][i+1]%=inf;
	}
	cout << (dp[0][s.size()]+dp[1][s.size()])%inf;
	// your code goes here
	return 0;
}