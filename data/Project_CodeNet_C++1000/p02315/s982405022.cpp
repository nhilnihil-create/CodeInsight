#include <iostream>
#include <algorithm>
using namespace std;


int dp[101][10001];
int item[101][2];
int n, w;


void makeDP(){
	for(int i = 0;i <= w;i++) dp[0][i] = 0;
	for(int i = 0;i <= n;i++) dp[i][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= w;j++){
			dp[i][j] = max(dp[i-1][j], j-item[i][1]>-1 ? dp[i-1][j-item[i][1]]+item[i][0] : 0);
		}
	}
}


int main(){
	cin >> n >> w;

	for(int i = 1;i <= n;i++) cin >> item[i][0] >> item[i][1];

	makeDP();

	cout << dp[n][w] << endl;

	return 0;
}