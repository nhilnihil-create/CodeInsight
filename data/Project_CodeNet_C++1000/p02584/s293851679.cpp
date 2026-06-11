#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("input.in", "r", stdin);
	// freopen("input.out", "w", stdout);
	ll x, k, d; cin >> x >> k >> d;
	ll ans;
	if (abs(x) / d <= k) {
		if ((k - abs(x) / d) & 1) ans = min(abs(abs(x) - (abs(x) / d + 1) * d), abs(abs(x) + (abs(x) / d + 1) * d));
		else ans = abs(x) - abs(x) / d * d;
	} else ans = abs(abs(x) - k * d);
	cout << ans << nl;
}