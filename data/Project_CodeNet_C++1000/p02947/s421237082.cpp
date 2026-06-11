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
	string s;
	map<string, int> mp;
	rep(i, 0, n - 1) {
		cin >> s;
		sort(all(s));
		mp[s]++;
	}
	int ans = 0;
	for (auto x : mp) {
		if (x.S > 1) {
			ans += x.S * (x.S - 1) / 2;
		}
	}
	cout << ans;
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