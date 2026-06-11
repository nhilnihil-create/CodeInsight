#include<bits/stdc++.h>
using namespace std;

long long N, X, Y;
long long dp[2005][2005];

int main(){
	cin >> N >> X >> Y;
	for(long long i = 0; i < 2005; i++) {
		for(long long j = 0; j < 2005; j++) {
			dp[i][j] = abs(i-j);
		}
	}

	X--;
	Y--;
	dp[X][Y] = 1;
	for(long long i = 0; i < 2005; i++) {
		for(long long j = 0; j < 2005; j++) {
			dp[i][j] = min(dp[i][j], dp[i][X] + dp[X][Y] + dp[Y][j]);
		}
	}
	map<long long, long long> memo;

	for(long long i = 0; i < N; i++) {
		for(long long j = i + 1; j < N; j++) {
			memo[dp[i][j]]++;
			//cout << "d[" << i << "][" << j << "] = " << dp[i][j] << endl;
		}
	}

	for(long long i = 1; i< N; i++){
		cout << memo[i] << endl;
	}


}
