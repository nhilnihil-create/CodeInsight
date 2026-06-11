#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5+100, INF = 1e9;

int dp[N][2];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;cin >> s;
	int n = s.size();
	for(int i=0 ; i<=n+10 ; i++)
		dp[i][0] = dp[i][1] = -INF;

	for(int i=n-1 ; i>=0 ; i--){
		// 2
		int cur = max(0, dp[i+2][0]);
		if(i >= n-3 || s[i] != s[i+2] || s[i+1] != s[i+3])
			cur = max(cur, max(0, dp[i+2][1]));
		if(i < n-1)
			dp[i][1] = cur + 1;
		// 1
		cur = max(0, dp[i+1][1]);
		if(i >= n-1 || s[i] != s[i+1])
			cur = max(cur, dp[i+1][0]);
		dp[i][0] = cur + 1;
	}

	cout << max(dp[0][0], dp[0][1]) << "\n";
 	return 0;
}














