#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define prec fixed << setprecision(12)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define test int t; cin >> t; while(t--)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

void solve() {
	ld a, b, x;
	cin >> a >> b >> x;
	ld ans;
	if (a * a * b / 2.0 <= x) {
		ans = atan(2 * (a * a * b - x) / (a * a * a));
	} else {
		ans = M_PI / 2 - atan(2 * x / (a * b * b));
	}
	cout << prec << ans * 180.0 / M_PI;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// test
	solve();

	return 0;
}