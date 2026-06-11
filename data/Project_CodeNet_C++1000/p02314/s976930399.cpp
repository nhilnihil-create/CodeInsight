#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c[30];
#define INF 1000000;

int main(){
	int dp[30][50010];

	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> c[i];
	}

	dp[0][0] = 0;
	for(int i = 1;i <= n;i++){
		dp[0][i] = INF;
	}

	for(int i = 0;i < m;i++){
		for(int j = 0;j <= n;j++){
			if(j < c[i]){
				dp[i + 1][j] = dp[i][j];
			} else {
				dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - c[i]] + 1);
			}
		}
	}

	cout << dp[m][n] << endl;

	return 0;
}