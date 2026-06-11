#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define bs(n) (1ul<<(n))

int n, t, a[3000], b[3000], dp[3001][6001] = { {0} }, dp2[3001][6001] = { {0} }, r = 0;

int main() {
	cin >> n >> t;
	rep(i, n)cin >> a[i] >> b[i];
	rep(i, n) {
		rep(j, t + 1) {
			dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + b[i]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
		rep(j, t + 1) {
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
		}
	}

	rrep(i, n) {
		rep(j, t + 1) {
			dp2[i][j + a[i]] = max(dp2[i][j + a[i]], dp2[i + 1][j] + b[i]);
			dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
		}
		rep(j, t + 1) {
			dp2[i][j + 1] = max(dp2[i][j + 1], dp2[i][j]);
		}
	}

	rep(i, n) {
		rep(j, t) {
			r = max(r, dp[i][j] + dp2[i + 1][(t - 1) - j] + b[i]);
		}
	}

	cout << r << endl;
}