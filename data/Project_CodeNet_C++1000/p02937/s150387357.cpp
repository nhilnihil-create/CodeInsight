#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(ll i = (ll)a; i <= (ll)b; i++)
#define DEC(i, a, b) for(ll i = (ll)a; i >= (ll)b; i--)
typedef pair<ll, ll> pi;
typedef pair<pi, ll> pii;
typedef pair<pi, pi> pipi;
#define f first
#define s second
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<pii> vpii;
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()
#define disc(v) sort(all(v)); v.resize(unique(all(v)) - v.begin());
#define INF (ll) 1e9 + 100
#define LLINF (ll) 1e18
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sandybridge __attribute__((optimize("Ofast"), target("arch=sandybridge")))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss

string s, t;
ll n, m, cur = -1, ans;
map<char, vi> pos;

int main() {
	fastio; cin >> s >> t;
	n = s.length(), m = t.length();
	FOR(i, 0, n-1) pos[s[i]].pb(i);
	FOR(i, 0, m-1) {
		#define v pos[t[i]]
		if (v.empty()) {
			cout << -1;
			return 0;
		}
		auto it = upper_bound(all(v), cur);
		if (it != v.end()) cur = *it;
		else cur = v[0], ans += n;
	}
	cout << ans + cur + 1;
}
