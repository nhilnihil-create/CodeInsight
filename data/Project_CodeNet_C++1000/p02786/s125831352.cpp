#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

int h, ans;
int foo(int n) {
	if (n == 1) return 1;
	return 1 + 2*foo(n/2);
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> h;
	ans = foo(h);
	cout << ans;
	time
}