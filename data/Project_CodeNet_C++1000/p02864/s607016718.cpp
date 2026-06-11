#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

int dp[310][310][310];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n + 1) rep(j, n + 1) rep(k, n + 1) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	rep(i, n) {
		rep(j, n) {
			rep(k, n) {
				int d;
				if (k != 0) d = max(0LL, a[i] - a[k - 1]);
				else d = a[i];
				chmin(dp[i + 1][j][i + 1], dp[i][j][k] + d);
				chmin(dp[i + 1][j + 1][k], dp[i][j][k]);
			}
		}
	}
	int ans = INF;
	rep(j, x + 1) {
		rep(k, n + 1) {
			chmin(ans, dp[n][j][k]);
		}
	}
	cout << ans << endl;
}