#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main() {
	const int MOD = 1000000007;
	int n, m;
	cin >> n >> m;
	vector<int> a(m), dp(n);
	for(int i = 0; i < m; i++){
		int in;
		cin >> in;
		a[i] = in - 1;
	}
	dp[0] = 1;
	dp[1] = 2;
	if(find(a.begin(), a.end(), 0) != a.end()){
		dp[0] = 0;
		dp[1] = 1;
	}
	if(find(a.begin(), a.end(), 1) != a.end()) dp[1] = 0;
	for(int i = 2; i < n; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
		if(find(a.begin(), a.end(), i) != a.end()) dp[i] = 0;
		if(dp[i] > MOD) dp[i] %= MOD;
	}
	cout << dp[n - 1] << endl;
}
