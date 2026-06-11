#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<ll> dp(n);
	dp[0] = 1000;
	for(int i = 1; i < n; i++){
		dp[i] = dp[i - 1];
		for(int j = 0; j < i; j++){
			ll count = dp[j] / a[j];
			dp[i] = max(dp[i], dp[j] + (a[i] - a[j]) * count);
		}
	}
	cout << dp[n - 1] << endl;
}
