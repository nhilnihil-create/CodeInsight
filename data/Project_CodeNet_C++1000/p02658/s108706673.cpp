#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 1, inf = 1e18;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) {
		cin >> a[i];
		if(a[i] == 0) ans = 0;
	}
	if(ans != 0) {
		rep(i,n) {
			ll x = inf;
			x /= ans;
			x /= a[i];
			if(x >= 1) ans *= a[i];
			else {
				ans = -1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
