#include <bits/stdc++.h>
using namespace std;
int dp[1000005][2];
int main() {
	string s;
	cin>>s;
	s='0'+s;
	dp[0][1]=1;
	int sz=s.size();
	for(int i=1; i<sz; i++){
		int num=int(s[i]-'0');
		dp[i][0]=min(dp[i-1][0]+num, dp[i-1][1]+10-num);
		dp[i][1]=min(dp[i-1][0]+num+1, dp[i-1][1]+(10-num-1));
	}
	cout<<dp[sz-1][0];
	return 0;
}