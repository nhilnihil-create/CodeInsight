#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n+1, vector<int>(3));
	dp[1][1] = 1;
	dp[2][2] = 1;
	for(int i = 1; i < n; i++){
		if(i > 0){
			if(s[i] != s[i-1]){
				//1->1
				dp[i+1][1] = dp[i][1]+1;
			}
			
		}
		if(i > 2){
			if(s[i] != s[i-2] || s[i-1] != s[i-3]){
				//2->2
				dp[i+1][2] = dp[i-1][2]+1;
			}
		}
		//2->1
		dp[i+1][1] = max(dp[i+1][1], dp[i][2]+1);
		//1->2
		dp[i+1][2] = max(dp[i+1][2], dp[i-1][1]+1);
	}
	cout << max(dp[n][1], dp[n][2]) << endl;
	return 0;
}
