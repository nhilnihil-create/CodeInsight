#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9+7;

signed main(){
	string s; cin >> s;
	vector<vector<lint> > dp(100010, vector<lint> (13, 0));
	dp[0][0] = 1;
	for(lint i = 0; i < s.size(); i++){
		for(lint j = 0; j < 13; j++){
			if(s[i] != '?'){
				lint x = s[i] - '0';
				dp[i + 1][(10 * j + x) % 13] += dp[i][j];
				dp[i + 1][(10 * j + x) % 13] %= MOD;
			}
			else{
				for(lint k = 0; k < 10; k++){
					dp[i + 1][(10 * j + k) % 13] += dp[i][j];
					dp[i + 1][(10 * j + k) % 13] %= MOD;
				}
			}
		}
	}
	cout << dp[s.size()][5] << endl;
}
