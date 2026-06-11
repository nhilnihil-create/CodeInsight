#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void add(int& a, int b){
	a += b;
	if(a >= mod){
		a -= mod;
	}
}

void sub(int& a, int b){
	a -= b;
	if(a < 0){
		a += mod;
	}
}

int main(void){
	int n, m;
	cin >> n >> m;
	vector<int> s(n + 1), t(m + 1);
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i];
	}
	for(int j = 1 ; j <= m ; j++){
		cin >> t[j];
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); 
	vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			add(sum[i][j], sum[i - 1][j]);
			add(sum[i][j], sum[i][j - 1]);
			sub(sum[i][j], sum[i - 1][j - 1]);
			if(s[i] != t[j]) continue;
			add(dp[i][j], sum[i - 1][j - 1] + 1);
			add(sum[i][j], dp[i][j]);
		}
	}
	int ans = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			add(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}