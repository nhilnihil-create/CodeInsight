#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;


#define INF 1001002003004005006ll

long long N, K;
long long H[305];
//idxを使う, いくつ消した？
long long dp[610][610];

int main(){
	cin >> N >> K;
	rep(i, N) cin >> H[i+1];
	H[N+1] = 0;

	rep(i, N + 5) rep(j, N + 5) dp[i][j] = INF;

	dp[0][0] = 0;

	for(long long i = 1; i <= N + 1; i++) {
		for(long long j = 0; j < i; j++) {
			//前回使ったのがj番目, 今回使うのがi番目
			long long jmp = i - j - 1;
			//kはjばんめで消した数
			for(long long k = 0; k <= i; k++) {
				if(dp[j][k] != INF && k + jmp <= K)
					dp[i][k+jmp] = min(dp[i][k+jmp], dp[j][k] + max(H[i] - H[j], 0LL));
			}
		}
	}

	long long ans = INF;
	rep(i, K+1) {
		ans = min(ans, dp[N+1][i]);
	}
	cout << ans << endl;



}

