#include <algorithm>
#include <iostream>
 
using namespace std;
 
const int N = 5000;
 
int dp[N + 1][N + 1];
 
int main() {
	int n; cin >> n;
	string s; cin >> s;
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j + 1] + 1;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1 + ans; j < n; j++)
			ans = max(ans, min(dp[i][j], j - i));
  
  
	cout << ans << '\n';
  
  
	return 0;
}