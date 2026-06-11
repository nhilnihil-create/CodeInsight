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

ll n, q, a, b, pre[200005], pos[200005], coun = 1;
vi adj[200005];
ll ft[200005];              // 1-index
ll ls(ll x){
	return (x & (-x));
}
// N means the largest possible index you need for the fenwick!! Refer to flowering for more.
void update(ll l, ll r, ll v){ // Updates from l to r inclusive
	r++;           // Update the difference at r+1 not r
	for(; l <= n; l += ls(l)) ft[l] += v;// Add v to the diff at l
	for(; r <= n; r += ls(r)) ft[r] -= v;// Minus v from diff at r+1
}
ll query(ll p){                     // Returns the element at p
	ll sum = 0;
	for(; p; p -= ls(p)) sum += ft[p];
	return sum; 
}

void dfs(ll x, ll p) {
	pre[x] = coun++;
	for (auto it:adj[x]) if (it != p) dfs(it, x);
	pos[x] = coun - 1;
}

int main() {
	fastio; cin >> n >> q;
	FOR(i, 1, n-1) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, -1);
	while (q--) {
		cin >> a >> b;
		update(pre[a], pos[a], b);
	}
	FOR(i, 1, n) cout << query(pre[i]) << " ";
}
