#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<cstring>

int main() {
	string s;
	cin >> s;
	ll dp[13] = {};
	ll n = s.size();
	//cout << n;
	int mul = 1;
	ll mod = 1000000007;
	dp[0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		ll ndp[13] = {};
		char c = s[i];
		if (c == '?') {
			for (int k = 0; k < 10; ++k) {
				for (int j = 0; j < 13; ++j) {
					ndp[(k * mul + j) % 13] += dp[j];//k*mulの余りだけ、dp[j]を平行移動する
					ndp[(k * mul + j) % 13] %= mod;
				}
			}
		}
		else {
			int k = (int)(s[i] - '0');
			//cout << k;
			for (int j = 0; j < 13; ++j) {
				ndp[(k * mul + j) % 13] += dp[j];//k*mulの余りだけ、dp[j]を平行移動する
				ndp[(k * mul + j) % 13] %= mod;
			}
		}
		mul *= 10;
		mul %= 13;
		//cout << endl;
		memcpy(dp, ndp, sizeof(dp));
		/*rep(i, 13) {
			cout << dp[i]<<" ";
		}
		cout << endl;
		*/
	}
	cout << dp[5];
	return 0;
}