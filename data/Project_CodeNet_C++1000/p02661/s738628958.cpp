#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define mp make_pair
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

		cin >> n;

		ll a[n], b[n];

		for (i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n);

		if (n % 2) {
			ll l = a[n / 2];
			ll r = b[n / 2];

			cout << r - l + 1 << endl;
		}
		else {
			ld l = (a[n / 2] + a[n / 2 - 1]) / 2.000;
			ld r = (b[n / 2] + b[n / 2 - 1]) / 2.000;

			ld diff = 2 * (r - l) + 1;

			cout << ll(diff) << endl;
		}





	}
}