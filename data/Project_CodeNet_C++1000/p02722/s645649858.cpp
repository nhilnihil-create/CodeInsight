#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

vector<ll> getdv(ll x) {
	vector<ll> ret;
	ll i;
	for(i = 2; i * i < x; i++) {
		if(x % i) continue;
		ret.push_back(i), ret.push_back(x / i);
	}
	if(i * i == x) ret.push_back(i);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll n;
	cin >> n;
	ll ans = getdv(n - 1).size() + 1;
	if(n > 2) ans++;
	auto cr = getdv(n);
	for(auto el: cr) {
		ll x;
		for(x = n; x % el == 0; x /= el);
		if(x % el == 1) ans++;
	}
	cout << ans << '\n';
}

