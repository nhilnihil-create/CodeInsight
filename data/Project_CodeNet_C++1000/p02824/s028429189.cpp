#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m, v, p;

bool can (ll pos, vector <ll> a) {
	ll left = m*(max(0ll, v-(n-pos+1)-p+1));
	int cnt = 0;
	a[pos] += m;
	for (int i=pos-1; i>=p; i--) {
		if (a[i] <= a[pos]) {
			left -= a[pos]-a[i];
			a[i] = a[pos];
		} else {
			cnt ++;
		}
	}
	return (left <= 0 && !cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> v >> p;
	vector <ll> a(n+1);
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	a[0] = 1e9+1;
	sort (a.begin(), a.end(), 
		[](const ll& x, const ll& y) {
			return (x > y);
		}
	);
	int bs = 0;
	for (int i=(1<<16); i>=1; i=(i>>1)) {
		if (i+bs > n) continue;
		if (can(i+bs, a)) {
			bs += i;
		}
	}
	cout << bs;
	return 0;
}
