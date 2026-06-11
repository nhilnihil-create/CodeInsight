#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
constexpr ll MOD = 1000000007;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<ll> dp(13);
	dp[0] = 1;
	rep(i, 0, s.size()) {
		vector<ll> next(13);
		rep(j, 0, 13) {
			if (s[i] == '?') {
				rep(k, 0, 10) {
					(next[(j * 10 + k) % 13] += dp[j]) %= MOD;
				}
			}
			else
				(next[(j * 10 + (s[i] - '0')) % 13] += dp[j]) %= MOD;
		}
		dp = next;
	}
	cout << dp[5] << endl;
	return 0;
}