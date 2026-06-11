#include <bits/stdc++.h>
#define maxn 2333
#define mod 1000000007
using namespace std;
typedef long long ll;
ll dp[maxn / 3][maxn];
int main() {
	int S;
	cin >> S;
	for(int j = 0; j <= S; ++j) dp[0][j] = 1;
	for(int i = 1; i <= S / 3; ++i) {
		for(int j = 3; j <= S; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 3]) % mod;
		}
//		cerr << i << endl;
	}
	ll ans = 0;
	for(int i = 1; i <= S / 3; ++i) ans = (ans + dp[i][S] - dp[i][S - 1] + mod) % mod;
	cout << ans;
	return 0;
}