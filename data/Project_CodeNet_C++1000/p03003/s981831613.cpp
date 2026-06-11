#include<bits/stdc++.h>
using namespace std;

#define DIV 1000000007

long long N, M;
long long S[20005];
long long T[20005];
long long dp[2005][2005];

int main(){
	cin >> N >> M;
	for(long long i = 1; i <= N; i++){
		cin >> S[i];
	}
	for(long long j = 1; j <= M; j++){
		cin >> T[j];
	}

	for(long long i = 0; i <= N; i++){
		dp[i][0] = 0;
	}
	for(long long i = 0; i <= M; i++){
		dp[0][i] = 0;
	}
	for(long long i = 1; i <= N; i++){
		for(long long j = 1; j <= M; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			if(S[i] == T[j]){
				dp[i][j]++;
			}else{
				dp[i][j] -= dp[i-1][j-1];
			}
			dp[i][j] = (dp[i][j]+ DIV) % DIV;
		}
	}

	cout << (dp[N][M] + 1)%DIV << endl;
}