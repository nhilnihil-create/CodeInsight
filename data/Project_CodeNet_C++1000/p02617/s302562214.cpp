#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
ll n, res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (ll i = 1; i <= n; i++)
		res += i * (i + 1) / 2;

	forn (i, n - 1) {
		ll u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		res -= u * (n - v + 1);
	}

	cout << res << endl;

	return 0;
}
