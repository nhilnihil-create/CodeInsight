#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

vector<pair<ll, ll>> prime_factorize(ll n) {
	vector<pair<ll, ll>> res;
	for (ll i=2; i*i <=n; i++) {
		if (n%i != 0) continue;
		ll ex = 0;
		while (n%i==0) {
			ex++; n /= i;
		}
		res.push_back({i, ex});
	}
	if (n != 1) res.push_back({n, 1});
	return res;
}


int main(int, char**) {
	ll a, b; cin >> a >> b;
	ll m, x;
	if (a < b) {
		m = a;
		x = b;
	} else {
		m = b;
		x = a;
	}

	vector<pair<ll, ll>> mfac = prime_factorize(m);
	int ret = 0;
	for (auto p : mfac) {
		if (x%(p.first)==0) ret++;
	}
	cout << ret + 1 << endl;

	return 0;
}