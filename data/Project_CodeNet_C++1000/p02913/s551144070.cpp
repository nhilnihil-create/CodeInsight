#include <iostream>
using namespace std;
#define myfill(a, val, type) fill((type *)a, (type *)a+sizeof(a)/sizeof(type), val)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }


int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	int dp[n+1][n+1]; myfill(dp, 0, int);
	for (int i = n-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if (s[i] == s[j]) dp[i][j] = dp[i+1][j+1] + 1;
			chmax(ans, min(abs(i-j), dp[i][j]));
		}
	}
	cout << ans << endl;
	return 0;
}