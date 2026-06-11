#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;



int main() {
	string s;
	cin >> s;
	int size = s.size();
	ll base = 1;

	ll dp[size + 1][13];
	rep (i, 13) {
		rep(j, size + 1) {
			dp[j][i] = 0;
		}
	}
	dp[0][0] = 1;
 
	rep(i, size) {
		int p = size - i - 1;
		if (s[p] == '?') {
			rep(from, 13) {
				rep(to, 10) {
					ll nj = (to * base + from) % 13;
					dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][from]) % mod;   
				}
			}
		} else {
			ll cur = s[p] - '0';
			rep(from, 13) {
				ll nj = (cur * base + from) % 13;
				dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][from]) % mod;
			}
		}

		base = (base * 10) % 13;

	}


	cout << dp[size][5] << endl;

	return 0;
}
