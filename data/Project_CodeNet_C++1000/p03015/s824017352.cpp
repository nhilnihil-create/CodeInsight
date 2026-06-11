#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
inline int ri() {
	int r; cin >> r; return r;
}
const ll mod = 1e9 + 7;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	for(auto &i : s)i -= '0';
	vector<vector<ll>> dp(n + 1, vector<ll>(2)); //i桁目まで見てフラグがj
	dp[0][0] = 1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {

			for(int d = 0; d <= (j ? 1 : s[i]); d++) {
				if(d == 0) {
					dp[i + 1][j || d < s[i]] += dp[i][j];
					dp[i + 1][j || d < s[i]] %= mod;
				}else {
					dp[i + 1][j || d < s[i]] += dp[i][j] * 2;
					dp[i + 1][j || d < s[i]] %= mod;
				}
			}
		}
	}
	//cout << dp[1][0] << " : " <<  dp[1][1] << endl;
	cout << (dp[n][0] + dp[n][1]) % mod  << endl;
}