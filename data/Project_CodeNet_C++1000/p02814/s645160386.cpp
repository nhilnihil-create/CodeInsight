#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;	cin >> n >> m;
	vector<ll> a(n);

	rep(i, n) {
		ll ii; cin >> ii;
		if (ii % 2 == 1) {
			cout << 0 << endl;
			return 0;
		}
		a[i] = ii / 2;
	}


	//cnt 2;
	int cnt = -1;
	rep(i, n) {
		int c = 0;
		ll b = a[i];
		while (true) {
			if (b % 2 == 1) break;
			b /= 2;
			c++;
		}

		if (cnt == -1) cnt = c;
		else if (cnt != c) {
			cout << 0 << endl;
			return 0;
		}
	}

	ll lc = 1;
	rep(i, n) {
		lc = lcm(lc, a[i]);
		if (lc > m) {
			cout << 0 << endl;
			return 0;
		}
	}

	ll ans = 0;
	for (ll i = lc; i <= m; i += lc * 2) ans++;
	cout << ans << endl;





	return 0;
}
