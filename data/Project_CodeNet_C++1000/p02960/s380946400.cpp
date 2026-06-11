#include<bits/stdc++.h>
using namespace std;

int main(){
	const long long MOD = 1000000007LL;
	
	string s;
	cin >> s;
	vector<vector<long long>> dp(100005,vector<long long>(13));

	int i,j,ki;
	long long res = 0;

	int n = s.size();
	dp[0][0] = 1;
	for(i=0; i<n; i++){
		int c;
		if(s[i]=='?') c = -1;
		else c = s[i] - '0';

		for(j=0; j<10; j++){
			if(c!=-1 && c!=j) continue;
			for(ki=0; ki<13; ki++){
				dp[i+1][(ki*10+j)%13] += dp[i][ki];
			}
		}
		for(j=0; j<13; j++) dp[i+1][j] %= MOD;
	}
	res = dp[n][5];

	cout << res << endl;
	return 0;
}
