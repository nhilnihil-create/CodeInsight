#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)(1e18)

signed main(){
	int N, K, i, j, k, jj, l;
	scanf("%lld%lld", &N, &K);
	vector<int> H(N + 1, 0), sorted_H(N + 1, 0);
	for(i = 1; i <= N; i++){
		scanf("%lld", &H[i]);
		sorted_H[i] = H[i];
	}
	sort(sorted_H.begin(), sorted_H.end());
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(N + 1, inf)));
	vector<vector<vector<int>>> min_from_l(N + 1, vector<vector<int>>(K + 1, vector<int>(N + 1, inf)));
	vector<vector<vector<int>>> min_minus_sorted_H_l_to_l(N + 1, vector<vector<int>>(K + 1, vector<int>(N + 1, inf)));
	dp[0][0][0] = 0;
	for(i = 1; i <= N; i++){
		for(j = 0; j <= K; j++){
			i--;
			min_from_l[i][j][N] = dp[i][j][N];
			for(k = N - 1; k >= 0; k--){
				min_from_l[i][j][k] = min(min_from_l[i][j][k + 1], dp[i][j][k]);
			}
			min_minus_sorted_H_l_to_l[i][j][0] = dp[i][j][0] - sorted_H[0];
			for(k = 1; k <= N; k++){
				min_minus_sorted_H_l_to_l[i][j][k] = min(min_minus_sorted_H_l_to_l[i][j][k - 1], dp[i][j][k] - sorted_H[k]);
			}
			i++;

			for(k = 0; k <= N; k++){
				if(sorted_H[k] == H[i]){
					jj = j;
				}
				else if(j == 0){
					continue;
				}
				else{
					jj = j - 1;
				}
				l = lower_bound(sorted_H.begin(), sorted_H.end(), sorted_H[k]) - begin(sorted_H);
				dp[i][j][k] = min(min_from_l[i - 1][jj][l], min_minus_sorted_H_l_to_l[i - 1][jj][l] + sorted_H[k]);
			}
		}
	}
/*	printf("sorted_H:\n");
	for(i = 0; i <= N; i++){
		printf("%lld ", sorted_H[i]);
	}
	printf("\n");
	printf("\n");
	for(i = 0; i <= N; i++){
		for(j = 0; j <= K; j++){
			for(k = 0; k <= N; k++){
				printf("dp[%lld][%lld][%lld] = %lld\n", i, j, k, dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
*/	int ans = inf;
	for(j = 0; j <= K; j++){
		for(k = 0; k <= N; k++){
			ans = min(ans, dp[N][j][k]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}