#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

int main(){
	int H, N;
	cin >> H >> N;
	int A[N], B[N];
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
	}
	int dp[N+1][H+1];
	for(int i=0;i<=N;i++){
		dp[i][0] = 0;
	}
	for(int j=1;j<=H;j++){
		dp[0][j] = inf;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=H;j++){
			dp[i][j] = min(min(dp[i-1][j], 
				dp[i-1][max(0, j - A[i-1])] + B[i-1]),
				dp[i][max(0, j - A[i-1])] + B[i-1]);
		}
	}
	cout << dp[N][H] << endl;
}
