#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	ll j_ans = inf;
	if (n == 1) {
		dunk(1);
		return 0;
	}
	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			ll nx = x[i] - x[j], ny = y[i] - y[j];
			ll ans = 0;
			rep(k, n)rep(l, n) {
				if (k == l) continue;
				if (x[k] - x[l] == nx && y[k] - y[l] == ny) ans++;
			}
			j_ans = min(j_ans, n - ans);
		}
	}
	dunk(j_ans);
	return 0;
}
