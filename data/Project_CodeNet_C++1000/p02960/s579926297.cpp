#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

string S;
ll dp[100005][20];

int main(){
	cin >> S;

	dp[0][0] = 1;

	rep(i, S.size()) {
		char ch = S[i];

		if(ch == '?') {
			rep(from, 13) {
				rep(num, 10) {
					dp[i + 1][(from * 10 + num)%13] += dp[i][from];
					dp[i + 1][(from * 10 + num)%13] %= DIV;
				}
			}
		} else {
			ll num = ch - '0';
			rep(from, 13) {
				dp[i + 1][(from * 10 + num)%13] += dp[i][from];
				dp[i + 1][(from * 10 + num)%13] %= DIV;
			}
		}
	}

	cout << dp[S.size()][5] << endl;
}