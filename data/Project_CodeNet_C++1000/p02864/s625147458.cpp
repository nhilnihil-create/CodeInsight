#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

ll dp[301][301];
void solve() {
	int n, k; cin >> n >> k;
	vector<int> h(n + 1);
	h[0] = 0;
	rep1(i, n)cin >> h[i];
	rep(i, 301) {
		rep(j, 301) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	rep(i, n + 1) {
		rep(j, i + 1) {
			if (dp[i][j] == INF)continue;
			for (int k = i + 1; k <= n; k++) {
				ll nd = dp[i][j];
				if (h[i] > h[k])nd += h[i] - h[k];
				dp[k][k - i - 1 + j] = min(dp[k][k - i - 1 + j], nd);
			}
		}
	}
	ll ans = INF;
	rep(i, n + 1) {
		rep(j, i + 1) {
			int dif = n - i;
			if (j + dif <= k) {
				ans = min(ans, dp[i][j] + h[i]);
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	stop
	return 0;
}