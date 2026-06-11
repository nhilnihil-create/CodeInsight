#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;
const int N = 100005;
int dp[N][13];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s; cin>>s;
	int n = s.size();
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		if(s[i - 1] != '?'){
			int val = s[i - 1] - '0';
			for(int j = 0; j < 13; j++){
				int nj = (10*j + val)%13;
				dp[i][nj] += dp[i - 1][j];
				if(dp[i][nj] >= mod)dp[i][nj] -= mod;
			}
		}else{
			for(int j = 0; j < 13; j++){
				for(int k = 0; k < 10; k++){
					int nj = (10*j + k)%13;
					dp[i][nj] += dp[i - 1][j];
					if(dp[i][nj] >= mod)dp[i][nj] -= mod;
				}
			}
		}
	}
	cout<<dp[n][5]<<'\n';

	return 0;
}