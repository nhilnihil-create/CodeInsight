#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true;} return false;}

long long a[110000];
long long dp[110000];
long long MOD = 1000000007;

int main() {
	rep(i,110000) dp[i]=0;
	dp[0] = 1;

	int n, m, num, prev_num;
        prev_num = -100;	
	cin >> n >> m;
	rep(i, n + 1) a[i] = true;
	rep(i, m) {
		cin >> num;
		if (num == prev_num + 1) {
			cout << 0 << endl;
			return 0;
		}
		a[num] = false;
		prev_num = num;
	}
	rep(i,n+1) {
		if(a[i+1]) {
			dp[i+1] += dp[i];
			dp[i+1] %= MOD;
		}
		if(a[i+2]) {
			dp[i+2] += dp[i];
			dp[i+2] %= MOD;
		}
	}
	cout << dp[n] << endl;
}
