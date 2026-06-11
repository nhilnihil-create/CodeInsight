#include <stdio.h>
#include <iostream>
using namespace std;




int main() {
	int n,wt;
	int v[105];
	int w[105];
	int dp[100010];
	
	cin >> n >> wt;

	for (int i=0;i<n;i++) {
		cin >> v[i] >> w[i];
	}

	for (int i=0;i<n;i++) {
		for (int j=wt;j>=w[i];j--) {
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		}
	}

	cout << dp[wt] <<endl;

	
	return 0;
}
