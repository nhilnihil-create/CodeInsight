#include<bits/stdc++.h>
using namespace std;

int main() {
	int dp[3001] = {};
	pair<int, int> ab[3000];
	int n, t;
	cin >> n >> t;
	for(int i = 0; i < n; i++) {
		cin >> ab[i].first >> ab[i].second;
	}
	sort(ab, ab + n);
	for(auto& p: ab) {
		for(int j = t - 1; j >= 0; j--) {
			int c = min(j + p.first, t);
			dp[c] = max(dp[c], dp[j] + p.second);
		}
	}
	cout << dp[t] << endl;
}
