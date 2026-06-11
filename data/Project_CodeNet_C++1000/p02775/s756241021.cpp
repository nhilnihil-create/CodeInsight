#include <bits/stdc++.h>

using namespace std;

string n;
int arr[1000010];
int dp[2][100010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	reverse(n.begin(), n.end());

	for(int i = 0; i < (int) n.size(); i++){
		arr[i] = n[i] - '0';
	}

	dp[0][0] = arr[0];
	dp[1][0] = 10 - arr[0];

	for(int i = 1; i < (int) n.size(); i++){
		dp[0][i] = dp[0][i - 1] + arr[i];
		dp[1][i] = dp[0][i - 1] + 10 - arr[i];

		if(arr[i] < 9) dp[0][i] = min(dp[0][i], dp[1][i - 1] + arr[i] + 1), dp[1][i] = min(dp[1][i], dp[1][i - 1] + 10 - (arr[i] + 1));
		else dp[1][i] = min(dp[1][i], dp[1][i - 1]);
	}

	cout << min(dp[0][n.size() - 1], dp[1][n.size() - 1] + 1) << "\n";

	return 0;
}