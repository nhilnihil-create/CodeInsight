#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define bs(n) (1ull<<(n))

map<ll, set<ll>> p;

pair<ll, ll> extgcd(ll a, ll b) {
	if (b == 0) return make_pair(a, 0);
	auto t = extgcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

ll mod = 1000000007;

ll rm(ll n) {
	auto t = extgcd(n, mod);
	return ((t.first % mod) + mod) % mod;
}

ll dm[200000] = { 0 };
ll fm(ll n) {
	if (n == 0) return 1;
	if (dm[n] == 0) dm[n] = (rm(n) * fm(n - 1)) % mod;
	return dm[n];
}

ll df[200000] = { 0 };
ll fc(ll n) {
	if (n == 0) return 1;
	if (df[n] == 0) df[n] = (n * fc(n - 1)) % mod;
	return df[n];
}

ll permutation(ll n, ll k) {
	if (n < k) return 0;
	return (fc(n) * fm(n - k)) % mod;
}

ll rec(ll node, ll anc, ll clr) {
	ll s = clr - 1;
	if (anc > 0) s--;
	ll c = 0;
	ll r = 1;
	for (auto& e : p[node]) {
		if (e == anc) continue;
		c++;
		r = (r * rec(e, node, clr)) % mod;
	}
	r = (r * permutation(s, c)) % mod;
	return r;
}

signed main() {
	ll n, k, a, b;
	cin >> n >> k;
	rep(i, n - 1) {
		cin >> a >> b;
		p[a].insert(b);
		p[b].insert(a);
	}
	cout << (rec(1, -1, k) * k) % mod << endl;
}
