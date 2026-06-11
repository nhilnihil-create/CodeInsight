#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 400000;

ll min(ll a, ll b) {
	if (a < b) { return a; }
	return b;
}

ll max(ll a, ll b) {
	if (a < b) { return b; }
	return a;
}


int main() {
	int N, K;
	cin >> N >> K;

	ll H[1000];
	H[0] = 0;
	repn(i, N) cin >> H[i];

	ll dp[1000][1000] = {};

	rep(i, N + 1) {
		rep(j, K + 1) {
			dp[j][i] = INF;
		}
	}

	dp[0][0] = 0;

	rep(j, K+1) {
		repn(i, N) {
			rep(k, min(j, i-1)+1) {
				dp[j][i]=min(dp[j][i],dp[j - k][i - k - 1] + max(H[i] - H[i - 1 - k], 0));
			}

			
		}

		
	}

	ll ans = dp[K][N];

	repn(j, K) {
		ans = min(ans, dp[K - j][N - j]);
	}

	cout << ans;

	system("PAUSE");

}