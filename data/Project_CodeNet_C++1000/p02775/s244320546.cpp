#include <bits/stdc++.h>
using namespace std;

int dp[2][1111111];

int main(){
	string S;
	cin >> S;
	vector<int> N(S.size());
	for(int i=0;i<S.size();i++)N[i]=S[i]-'0';
	
	dp[1][0]=1;
	
	for(int i=0;i<N.size();i++){
		dp[0][i+1]=min(dp[0][i]+N[i],dp[1][i]+10-N[i]);
		dp[1][i+1]=min(dp[0][i]+N[i]+1,dp[1][i]+9-N[i]);
	}
	cout << dp[0][N.size()] << endl;
	return 0;
}