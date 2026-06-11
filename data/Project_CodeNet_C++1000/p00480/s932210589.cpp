#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	long long int dp[21][110] = {0};
	dp[data[0]][0] = 1;
	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < 21; j++) {
			if (j+data[i] <= 20) {
				dp[j+data[i]][i] += dp[j][i-1];
			}
			if (j-data[i] >= 0) {
				dp[j-data[i]][i] += dp[j][i-1];
			}
		}
	}
	/*for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < 21; j++) {
			cout << dp[j][i] << ' ';
		}
		cout << endl;
	}*/
	cout << dp[data[n-1]][n-2] << endl;
	return 0;
}