#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)

using namespace std;

string S;

//上からの下げを発生させる
#define SAGE 0
//上からの下げを発生させない
#define NO 1

long long dp[1000005][2];

int main(){
	cin >> S;
	reverse(S.begin(), S.end());
	S += '0';
	long long N = S.size();

	rep(i,N+2)rep(j,2)dp[i][j] = LONG_MAX/5;

	dp[0][NO] = 0;

	rep(i, N) {
		long long num = S[i] - '0';

		//SAGEからの遷移
		rep(j, 10) {
			long long mina = num + 1;
			if(mina > j) {
				// -> SAGE
				dp[i+1][SAGE] = min(dp[i+1][SAGE], dp[i][SAGE] + j + (10 + j - mina)); 

			} else {
				// -> NO
				dp[i+1][NO] = min(dp[i+1][NO], dp[i][SAGE] + j + (j - mina)); 
			}

		}

		//NOからの遷移
		rep(j, 10) {
			long long mina = num;
			if(mina > j) {
				// -> SAGE
				dp[i+1][SAGE] = min(dp[i+1][SAGE], dp[i][NO] + j + (10 + j - mina)); 
			} else {
				// -> NO
				dp[i+1][NO] = min(dp[i+1][NO], dp[i][NO] + j + (j - mina)); 
			}
		}

	}

	cout << dp[N][NO] << endl;
}
