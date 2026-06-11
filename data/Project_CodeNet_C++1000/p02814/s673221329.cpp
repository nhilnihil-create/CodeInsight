// first second push_back unordered return continue break vector visited check flag bool while iterator begin end lower_bound upper_bound temp true false ll_MAX ll_MIN insert erase clear pop push compare ll64_MAX ll64_MIN  reverse replace stringstream string::npos length substr front priority_queue

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#endif

#define endl '\n'
#define ll long long
#define rint register int
#define minpq priority_queue <int, vector<int>, greater<int> >
#define maxpq  priority_queue <int>

#define re register
#define pb(x) push_back(x);
#define ce(x) cout << x << '\n';

using db = long double;
using pll = pair < ll, ll >;
#define scan(a, n) 		for(int i = 0; i < n; i++)cin >> a[i];

#define rep(i,x,n,inc) for(i=x ; i<n ; i+=inc)
#define repr(i,x,n,inc) for( i=x ; i>n ; i+=inc)
#define all(a)      (a).begin(),(a).end()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define hell 1000000007

long long gcd (long long a, long long b) {
	return b ? gcd (b, a % b) : a;
}

ll lcm(ll x, ll y) {
	return (x / gcd(x, y)) * y;
}

#define tc(tt) \
    ll tt;    \
    cin >> tt; \
    for (ll _tt = 0; _tt < tt; _tt++) // testcase 

int32_t main() {
	ios::sync_with_stdio(0); 		cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t, i, x, m, j, y, 	z, k, n;
	cin >> n >> m;
	ll a[n];
	rep(i, 0, n, 1) {
		cin >> a[i];
	}
	x = a[0] / 2;
	ll lc = x;
	t = 0;
	while (x % 2 == 0) {
		t++;
		x /= 2;
	}

	rep(i, 1, n, 1) {
		x = a[i] / 2;
		y = 0;
		lc = lcm(lc, x);
		while (x % 2 == 0) {
			y++;
			x /= 2;
		}
		if (y != t) {
			return cout << 0, 0;
		}
	}


	z = 0;
	// debug("z");


	ll odd = m / lc;
	if (odd % 2 == 0)	odd--;

	z = max(z, (odd + 1) / 2);
	return cout << z, 0;

}

