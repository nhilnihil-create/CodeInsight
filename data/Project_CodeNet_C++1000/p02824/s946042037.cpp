#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;

ll n, m, v, p;
vector<ll> a;

bool val(ll points) {
	auto it = upper_bound(all(a), points);
	ll tot = m * (v - 1);
	int cnt = 0;
	bool impossible = false;
	for (int i = distance(a.begin(), it); i <= sz(a) - p; ++i) {
		++cnt;
		if (a[i] > points + m) {
			impossible = true;
			break;
		} else {
			tot -= points + m - a[i];
		}
	}
	
	tot -= ((n - cnt - 1) * m);
	return (!impossible && tot <= 0);
}

ll bsearch(ll l, ll r) {
	if (l == r) return l;
	if (l + 1 == r) {
		if (val(l)) return l;
		return r;
	} else {
		ll mid = (l + r) / 2;
		if (val(mid)) return bsearch(l, mid);
		else return bsearch(mid + 1, r);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> v >> p;
	a.resize(n);
	for (auto& i : a) cin >> i;
	sort(all(a));
	ll bound = bsearch(0, 1e9);
	auto it = lower_bound(all(a), bound);
	int cnt = 0;
	while (it != a.end()) {
		++cnt, ++it;
	}
	cout << cnt;
}
