#include <bits/stdc++.h>
//<(") 
#define ll long long 
using namespace std;
 
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
 
const ll mod = 998244353;
const ll siz = 3e3 + 10;
const ll base = 32;
const ll MAXX = 1e18;

ll n, s;
vector<ll> hold;

ll res[siz][siz];

ll dp(ll pos, ll rem) {
	if (pos >= n) {
		return rem == 0;
	}
	ll &ans = res[pos][rem];
	if (ans != -1) {
		return ans;
	}
	ans = (dp(pos + 1, rem) * 2) % mod;
	if (rem - hold[pos] >= 0) {
		ans = (ans + dp(pos + 1, rem - hold[pos])) % mod;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("INP.txt", "r", stdin);
	//freopen("OUT.txt", "w", stdout);
	cin >> n >> s;
	hold.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> hold[i];
	}
	memset(res, -1, sizeof(res));
	cout << dp(0, s) << '\n';
	return 0;
}