#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define mp make_pair
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

int n;
vector <int> a;
vector <int> s;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	rep(i, 0, n, 1) {
		int x; cin >> x;
		a.pb(x);
		s.pb(x);
	}
	sort(s.rbegin(), s.rend());
	int max = s[0];
	rep(i, 0, n, 1) {
		if (max != a[i]) cout << max << '\n';
		else cout << s[1] << '\n';
	}
}