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
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	
	string s, t;
	cin >> s >> t;
	int n = s.size(); int m = t.size();
	string k = s + s;
	vector<vector<int>> pl(26, vector<int>());
	rep(i, 2 * n) pl[k[i] - 'a'].pb(i);
	rep(i, 26) pl[i].pb(2 * n);
	int now = -1; int cnt = 0;
	rep(i, m) {
		int c = t[i] - 'a';
		int idx = upper_bound(all(pl[c]), now) - pl[c].begin();
		int nxt = pl[c][idx];
		if (nxt == 2 * n) {
			cout << -1 << '\n';
			return 0;
		}
		if (nxt >= n) {
			now = nxt - n; cnt++;
		}
		else now = nxt;
	}
	cout << (ll)cnt*n + now + 1 << '\n';
}