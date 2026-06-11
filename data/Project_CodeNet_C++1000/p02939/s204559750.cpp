#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[214514][3];
int main() {
	string s;
	cin>>s;
	dp[0][1]=1;
	dp[1][1]=2;
	dp[1][2]=1;
	if(s[0]==s[1])dp[1][1]=1;
	for(int i=2;i<s.size();i++){
		dp[i][1]=dp[i-1][2]+1;
		if(s[i]!=s[i-1])dp[i][1]=max(dp[i][1],dp[i-1][1]+1);

		dp[i][2]=dp[i-2][1]+1;
		if(i>2&&s.substr(i-1,2)!=s.substr(i-3,2))dp[i][2]=max(dp[i][2],dp[i-2][2]+1);
	}
	cout<<max(dp[s.size()-1][1],dp[s.size()-1][2]);
	return 0;
}
