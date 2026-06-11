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
	int n;
	cin >> n;
	vector<ld> v(n);
	rep(i, 0, n - 1) cin >> v[i];
	sort(all(v));
	ld ans = 0;
	int base = 2;
	ans += v[0] + v[1];
	rep(i, 2, n - 1) {
		ans += base * v[i];
		base *= 2;
	}
	// cout << ans;
	cout << prec << ans / pow(2, n - 1);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#define TEST 0

	if (TEST) {
		test;
		solve();
	} else {
		solve();
	}

	return 0;
}