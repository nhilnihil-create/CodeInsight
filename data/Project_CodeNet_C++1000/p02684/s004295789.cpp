#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, k, ans = 1e18;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i,n) {
		cin >> a[i];
		a[i]--;
	}

	ll now = 0;
	vector<ll> move(n, -1);
	move[0] = 0;
	for (ll i = 1; i <= k; ++i) {

		if (move[a[now]] >= 0) {
			ll num = (k - i) % (i - move[a[now]]);
			now = a[now];
			for (ll j = 0; j < num; j++) {
				now = a[now];
			}
			break;
		}
		else {
			now = a[now];
			move[now] = i;
		}
	}
	ans = now + 1;
	cout << ans << endl;
	return 0;
}
