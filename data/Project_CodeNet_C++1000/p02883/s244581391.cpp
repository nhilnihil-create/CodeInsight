#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr ll inf = 1e18;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> f[i];
	sort(a.begin(), a.end());
	sort(f.rbegin(), f.rend());
	ll ok = inf, ng = -1;
	while (ok - ng > 1) {
		ll mid = (ok + ng) / 2;
		ll cnt = 0;
		rep(i, n) {
			if (a[i] > mid / f[i]) cnt += a[i] - mid / f[i];
		}
		if (cnt <= k) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
	return 0;
}
