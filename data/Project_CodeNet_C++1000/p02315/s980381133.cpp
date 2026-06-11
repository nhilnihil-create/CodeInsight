#include<stdio.h>
#include<algorithm>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <functional>
using namespace std;

int dp[101][100001] = { 0 };
int N, v[100], w[100], W;

int main(void) {
	int sum = 0;
	scanf("%d %d", &N, &W);
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &v[i], &w[i]);
		sum += v[i];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= W; ++j) {
			if (j < w[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			}
			else{
				dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d\n", dp[N][W]);
}