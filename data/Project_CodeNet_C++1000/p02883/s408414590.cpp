#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> f[i];
	sort(ALL(a));
	sort(ALL(f), greater<ll>());
	ll l = -1;
	ll r = 1000000000000;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		ll p = k;
		bool b = true;
		rep(i,n) {
			ll t = 0;
			if (f[i] > mid) t = a[i];
			else if (a[i] * f[i] > mid) {
				t = (a[i] * f[i] - mid + f[i] - 1) / f[i];
			}
			if (p - t < 0) {
				b = false;
				break;
			}
			p -= t;
		}
		if (b) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << endl;
}