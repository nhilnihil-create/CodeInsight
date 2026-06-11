#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

int n;
vector <int> v;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	bool yay = false;
	int ans = 0;
	cin >> n;
	rep(i, 0, n, 1) {
		int x; cin >> x;
		if (x == 1) yay = true;
		v.pb(x);
	}
	if (!yay) cout << -1;
	else {
		bool ok = false;
		int next = 2;
		rep(i, 0, n-1, 1) {
			if (v[i] == 1) ok = true;
			if (!ok) {
				++ans;
				continue;
			}
			else {
				if (v[i+1] != next) ++ans;
				else ++next;
			}
		}
		cout << ans;
	}
	time
}