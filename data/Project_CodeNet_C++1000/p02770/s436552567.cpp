#include <bits/stdc++.h>
using namespace std;
#define DEBUG 0
#define nl          '\n'
#define fori(n)			for(int i = 0; i < n; ++i) 
#define forj(n)			for(int j = 0; j < n; ++j)
#define fork(n)			for(int k = 0; k < n; ++k)
#define forl(n)			for(int l = 0; l < n; ++l)
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define ppb push_back
typedef long long ll;typedef pair<int,int> pii;typedef vector<bool> vbool;
typedef vector<int> vint;typedef vector<ll> vll;typedef long double ld;
typedef vector<vector<int>> vvi; typedef vector<vbool> vvb;

const ll N = 100010;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll k, q; cin >> k >> q;
	vll d(k), pre(k+1, 0);
	fori(k) cin >> d[i];
	ll n, x, m;
	fori(q) {
		cin >> n >> x >> m;
		fori(k) pre[i+1] = pre[i] + d[i]%m;
		ll ans = 0, last = x + (n-1)/k * pre[k] + pre[(n-1)%k], sub = 0;
		forj(min(k, n)) {
			ll cur = d[j]%m;
			if (cur == 0) {
				sub += (n-1)/k;
				if ((n-1)%k >= (j+1)) sub++;
			}
		}
		sub += (last/m - x/m);

		ans = n-1-sub;
		cout << ans << nl;
	}

	#if DEBUG
	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << " s" << nl;
	#endif
	return 0;
}
