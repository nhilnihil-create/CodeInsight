#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

#define INF LONG_MAX/3

long long N, M;

long A[1005];
long state[1005];
long long dp[1005][5000];

int main(){
	cin >> N >> M;

	rep(i, M) {
		long long b;
		cin >> A[i];
		cin >> b;

		long long s = 0;
		rep(j, b) {
			long long c;
			cin >> c; c--;
			s += (1<<c);
		}
		state[i] = s;
	}

	rep(i, 1005) rep(j, 5000) dp[i][j] = INF;

	dp[0][0] = 0;
	rep(i, M) {
		long long s = state[i];
		rep(j, 5000) {
			if(dp[i][j] == INF) continue;

			//使う
			dp[i+1][j|s] = min(dp[i+1][j|s], dp[i][j] + A[i]);
			//使わない
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
		}
	}

	if(dp[M][(1<<N)-1] == INF) {
		cout << -1 << endl;
	} else {
		cout << dp[M][(1<<N)-1] << endl;
	}





}