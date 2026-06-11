#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	ll n, m, k, ans = 0;
	cin >> n >> m >> k;
	vector<ll> a(n + 1), b(m + 1);
	a[0] = 0;
	b[0] = 0;
	rep(i,n) {
		cin >> a[i + 1];
		if (i != 0) a[i + 1] += a[i];
	}
	rep(i,m) {
		cin >> b[i + 1];
		if (i != 0) b[i + 1] += b[i];
	}
	ll ng = n + m + 1, ok = 0;
	while (abs(ng - ok) > 1) {
		ll mid = (ng + ok) / 2;
		bool c = false;
		rep(i,mid + 1) {
			if (i <= n && mid - i <= m) {
				if (a[i] + b[mid - i] <= k) c = true;
			}
		}
		if(c) ok = mid;
		else ng = mid;
	}
	ans = ok;
	cout << ans << endl;
	return 0;
}
