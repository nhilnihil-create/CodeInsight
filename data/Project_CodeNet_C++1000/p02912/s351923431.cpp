#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;
#define get(vv, times) for(int ii = 0; ii < times; ++ii) {int jj; cin >> jj; (vv).pb(jj);}

int n, m, ans;
priority_queue <int> pq;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ans = 0;
	cin >> n >> m;
	rep(i, 0, n, 1) {
		int x; cin >> x;
		pq.push(x);
	}
	rep(i, 0, m, 1) {
		int mx = pq.top();
		// apply discount be like
		pq.pop();
		pq.push(mx/2);
	}
	rep(i, 0, n, 1) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
}