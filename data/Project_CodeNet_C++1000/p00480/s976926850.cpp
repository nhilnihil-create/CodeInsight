#include<iostream>
using namespace std;
int main(){
	int n, num[120];
	long long int dp[120][30] = {0};
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}

	dp[0][num[0]] = 1;
	for (int i = 0; i < n-2; i++){
		for (int j = 0; j <= 20 ; j++){
			if (j + num[i+1] <= 20){
				dp[i+1][j + num[i+1]] += dp[i][j];
			}
			if (j - num[i+1] >= 0){
				dp[i+1][j - num[i+1]] += dp[i][j];
			}
		}
	}
	/*for (int i = 0; i <= 20; i++){
		for (int j = 0; j < n; j++){
			cout << dp[j][i] << " ";
		}
		cout << endl;
	}*/
	cout << dp[n-2][num[n-1]] << '\n';

	return 0;
}