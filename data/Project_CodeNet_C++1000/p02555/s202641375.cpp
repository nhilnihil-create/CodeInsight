#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}


int main() {
	int s;
	cin >> s;
	vector<int> dp(s+1);
	dp[0] = 1;
	int x = 0;
	for (int i = 1; i <= s;i++) {
		if (i >= 3) {
			x += dp[i - 3];
			x %= mod;
			dp[i] += x;
			dp[i] %= mod;
		}
	}
	cout << dp[s] << endl;
}