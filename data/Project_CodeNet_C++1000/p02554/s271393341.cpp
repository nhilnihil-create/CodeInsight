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
#define infl LLONG_MAX

ll powmod(ll x, ll k) {
	ll ans = 1;
	for (; k; k >>= 1, x = (x * x) % hell)
		if (k & 1)
			ans = (ans * x) % hell;
	return ans % hell;
}

int32_t main() {
	ios::sync_with_stdio(0); 		cin.tie(0); cout.tie(0);

	ll t, i, x, j, y, 	z, k, n;
	cin >> n;

	t = powmod(10, n) - 2 * powmod(9, n) + powmod(8, n);
	t %= hell;	t += hell;	t %= hell;

	ce(t);
}

