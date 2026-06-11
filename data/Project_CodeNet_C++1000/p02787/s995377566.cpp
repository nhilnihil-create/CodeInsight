#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 5;


int main() {
	int H, n;
	cin >> H >> n;
	// Similar to creating an array dp[h+1] but this one is better
	vector<int> dp(H + 1, INF); //dp[h]
	// dp[x] - minimum total cost to get value x
	dp[0] = 0;
	while(n--){
		int value, cost;
		cin >> value >> cost;
		for(int i = 0; i <= H; i++){ // O(N*H)
			// dp[i] -> dp[i+value]
			int j = min(H, i + value);
			dp[j] = min(dp[j], dp[i] + cost);
		}
	}
	cout << dp[H] << endl;
}