#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define len(s) s.length()
#define all(v) v.begin(),v.end()
const ll INF = INT_MAX;
const int N = 2e5 + 5;
const ll mod = 1000000007 ;
using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	ll tc = 1;
	// cin >> tc;
	while (tc--) {

		ll n, m, l, r;
		ll i, j;
		ll x, y;
		// cin >> n;

		ll h1, m1, h2, m2, k;

		cin >> h1 >> m1 >> h2 >> m2 >> k;

		ll totmin1 = h1 * 60 + m1;
		ll totmin2 = h2 * 60 + m2;

		totmin2 = totmin2 - k;

		ll ans = totmin2 - totmin1;
		cout << ans << endl;
	}
}