#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

ll fact[4005], invfact[4005];
const ll mod = 1'000'000'007;

ll bm(ll b, ll p, ll m) {
	ll r = 1;
	for (; p; p >>= 1, b = b * b % m) if (p & 1) r = r * b % m;
	return r;
}

ll modinv(ll b) { return bm(b, mod - 2, mod); }
ll ncr(ll n, ll r) { 
	//printf("%lldC%lld\n", n, r);
	if (r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod; 
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	fact[0] = 1;
	rep(i, 1, 4005) fact[i] = fact[i - 1] * i % mod;
	rep(i, 0, 4005) invfact[i] = modinv(fact[i]);

	int n, k; read(n, k);
	int blue = k, red = n - k;

	vector<int> ans(k + 1);
	rep(i, 1, k + 1) {
		ll bb = ncr(blue - 1, i - 1);
		ll rr = ncr(red - (i - 1) + (i + 1) - 1, i);
		ans[i] = bb * rr % mod;
		//printf("%d: BB=%lld RR=%lld\n", i, bb, rr);
		//printf("Solve %d\n", i);
	}

	rep(i, 1, k + 1) write(ans[i]);
}
