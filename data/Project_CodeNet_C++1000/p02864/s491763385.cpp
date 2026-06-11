#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#define mk make_pair
#define pb push_back
#define scanf scanf_s
#define printf printf_s
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> pos;
const ll N = 310, MOD = 1000000007;

ll mn(ll a, ll b) {
	if (a == -1)return b;
	if (b == -1)return a;
	return min(a, b);
}

int bb(int v1) {
	if (v1 % 2 == 0)return v1 / 2 - 1;
	else return v1 / 2;
}

ll pw(ll a, ll b) {
	ll v = 1;
	for (; b > 0; b = (b >> 1), a = (a * a) % MOD) {
		if ((b & 1) > 0)v = (v * a) % MOD;
	}
	return v;
}

ll h[N],dp[N][N][N],n,k;

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> h[i];
	for (int i = 0; i < n; i++) {
		for (ll j = 0; j <= k; j++) {
			for (int l = 0; l <= i; l++) {
				if (dp[i][j][l] == -1)continue;
				ll v1 = h[l];
				if (j + 1 <= k && v1!=h[i+1]) {
					dp[i + 1][j + 1][l] = mn(dp[i + 1][j + 1][l], dp[i][j][l]);
				}
				if (v1 != h[i + 1])
					dp[i + 1][j][i + 1] = mn(dp[i + 1][j][i + 1], dp[i][j][l] + max((ll)0, h[i + 1] - v1));
				else
					dp[i + 1][j][i + 1] = mn(dp[i + 1][j][i + 1], dp[i][j][l]);
			}
		}
	}
	ll ans = -1;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			ans = mn(ans, dp[n][i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
