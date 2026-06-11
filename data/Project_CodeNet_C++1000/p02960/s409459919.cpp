#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

ll dp[100001][13];

int main(){
	string s;
	cin >> s;
	int n = s.size();
	const ll mod = 1000000007;
	
	REP(i,13) dp[0][i] = 0;
	dp[0][0] = 1;
	
	REP(i,n){
		if(s[i]=='?'){
			REP(j,13){
				REP(k,10){
					int now = (10*j+k)%13;
					dp[i+1][now] += dp[i][j];
					dp[i+1][now] %= mod;
				}
			}
		}else{
			REP(j,13){
				int now = (10*j+(int)(s[i]-'0'))%13;
				dp[i+1][now] += dp[i][j];
				dp[i+1][now] %= mod;
			}
		}
	}
	
	cout << dp[n][5] << endl;
	
	return 0;
}