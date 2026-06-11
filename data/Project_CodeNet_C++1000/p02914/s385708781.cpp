#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll K = 62;

bool bit(ll x, ll k) {
	return x & (1LL << k);
}

bool has_subset(vl a, ll s) {
	ll n = sz(a);
	
	ll r = 0;
	FOR(k,0,K) {
		if (r == n) break;
		FOR(i,r,n) {
			if (bit(a[i],k)) {
				swap(a[i],a[r]);
				break;
			}
		}
		if (!bit(a[r],k)) continue;
		
		FOR(i,r+1,n) if (bit(a[i],k)) a[i] ^= a[r];

		if (bit(s,k)) s ^= a[r];
		r++;
	}
	return s == 0;	
}

bool has_subset_naive(vl a, ll s) {
	ll n = sz(a);
	FOR(mask,0,1 << n) {
		ll x = 0;
		FOR(i,0,n) if (mask & (1 << i)) x ^= a[i];
		if (x == s) return true;
	}
	return false;
}

void stress() {
	FOR(i,0,1000) {
		ll n = 1 + rand() % 5;
		vl a(n);
		FOR(i,0,n) a[i] = rand() % 16;
		ll s = rand() % 16;
	
		if (has_subset(a,s) != has_subset_naive(a,s)) {
			cout << has_subset(a,s) << endl;
			for (ll x: a) cout << x << " ";
			cout << s << endl;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// stress();

	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll s = 0;
	FOR(i,0,n) s ^= a[i];
	
	ll x = 0;
	FORD(k,0,62) {
		if (s & (1LL << k)) {
			FOR(i,0,n) a[i] &= ~(1LL << k);
		} else {
			vl b(n);
			FOR(i,0,n) b[i] = a[i] >> k;
			if (has_subset(b, (x >> k) | 1)) x |= 1LL << k;
			// cerr << k << " " << x << endl;
		}
	}

	ll res = x + (s^x);
	cout << res << endl;
}

