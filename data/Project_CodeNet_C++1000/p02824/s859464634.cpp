#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, res;
ll m, v, p, a[MX], acu[MX];

bool valid (ll lim, ll n, ll v) {
	ll j = lower_bound(a, a + n, lim - m) - a;
	ll s = lim * (n - j) - (acu[n - 1] - (j ? acu[j - 1] : 0)) + j * m;

	return s >= m * v;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> v >> p;
	forn (i, n) cin >> a[i];
	sort (a, a + n);

	forn (i, n) {
		acu[i] = a[i];
		if (i) acu[i] += acu[i - 1];
	}

	forn (i, n) {
		if (n - i <= p) {
			res++;
			continue;
		}

		ll lim = a[i] + m;
		int j = upper_bound(a, a + n, lim) - a;

		if (n - j >= p) continue;

		res += valid(lim, n - (p - 1), max(0ll, v - p + 1));
	}

	cout << res << endl;

	return 0;
}