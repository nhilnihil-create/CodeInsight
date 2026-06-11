#include<stdio.h>
#include<stdlib.h>

int v[100];
int w[100];
int dp[101][10001];
int main(int argc, char* argv){
	int N, W;
	int i, j;
	scanf("%d %d", &N, &W);
	for(i = 0; i < N; i++){
		scanf("%d %d", &v[i], &w[i]);
	}

	for(i = 0; i < W; i++){
		dp[0][i] = 0;
	}

	for(i = 0; i < N; i++){
		for(j = 0; j <= W; j++){
			if(j - w[i] >= 0 && dp[i][j - w[i]] + v[i] > dp[i][j]){
				dp[i + 1][j] = dp[i][j - w[i]] + v[i];
			}else{
				dp[i + 1][j] = dp[i][j];
			}
		}
	}
/*
	for(i = 0; i <= N; i++){
		for(j = 0; j <= W; j++){
			printf("%3d", dp[i][j]);
		}
		printf("\n");
	}
*/

	printf("%d\n", dp[N][W]);
}