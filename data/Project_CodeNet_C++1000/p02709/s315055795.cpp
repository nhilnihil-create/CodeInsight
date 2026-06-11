#include<bits/stdc++.h>
using namespace std;
const int NAX = 2e3 +1;
long long dp[NAX][NAX];

long long fabs(int x, int y, int z) {
  	return x * 1LL * abs(y - z);
}

int main() {
	int N;
	cin >> N;
  	vector<pair<int, int>> arr(N);
	for (int i = 0; i < N; ++i) {
    	cin >> arr[i].first;
     	arr[i].second = i;
    }
 	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; ++i) {
    	dp[i][i] = fabs(arr[0].first, arr[0].second, i);
    }
	for (int i = 2; i <= N; ++i) {
    	for (int x = 0; x + i - 1 < N; ++x) {
			int y = x + i - 1;
	        dp[x][y] = max(dp[x + 1][y] + fabs(arr[i - 1].first, arr[i - 1].second, x), 
                          dp[x][y - 1] + fabs(arr[i - 1].first, arr[i - 1].second, y));
        }
    }
  	cout << dp[0][N - 1] << endl;
  	return 0; 
}