#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d[2007] = {0};
const ll m = 1e9+7;

void solve(ll x) {
	ll res = 0;
	for (int i = 0; i <= x - 3; ++i) {
		res = (res + d[i]) % m;
	}
	d[x] = res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	d[0] = 1;
	for (ll i = 1; i <= n; ++i) {
		solve(i);
	}
	cout << d[n] << endl;
	return 0;
}