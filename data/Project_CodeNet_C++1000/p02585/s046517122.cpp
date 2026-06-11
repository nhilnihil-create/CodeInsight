#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a % MOD;
	while (b > 0) {
		if (b & 1) {res = (res * a) % MOD; b--;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vl p(n + 1), c(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> p[i];
	for (ll i = 1; i <= n; i++)
		cin >> c[i];
	ll ans = -2e13;
	for (ll i = 1; i <= n; i++) {
		ll cur = p[i];
		ll cvalue, csize;
		cvalue = csize = 0;
		ll j = i;
		do {
			j = p[j];
			cvalue += c[j];
			csize++;
		} while (j != i);
		//cout << cvalue << "\n";
		ll rem, cbest, rem1, cbest1;
		rem = rem1 = k;
		cbest = cbest1 = 0;
		if (cvalue > 0 && k >= csize) {
			rem = k;
			cbest = 0;
			cbest += (k / csize) * cvalue;
			rem %= csize;
			rem1 = k;
			cbest1 = 0;
			cbest1 += (k / csize - 1) * cvalue;
			rem1 %= csize;
			rem1 += csize;
		}
		ll ma = -2e13;
		ll ma1 = -2e13;
		if (rem == 0)
			ma = 0;
		if (rem1 == 0)
			ma1 = 0;
		ll t = 0;
		j = i;
		ll curr = 0;
		do {
			j = p[j];
			curr += c[j];
			t++;
			if (t <= rem)
				ma = max(ma, curr);
			if (t <= rem1)
				ma1 = max(ma1, curr);
		} while (j != i);
		cbest += ma;
		cbest1 += ma1;
		//cout << cbest << " " << cbest1 << "\n";
		ans = max(ans, cbest);
		ans = max(ans, cbest1);
		//cout << cbest << " " << cbest1 << "\n";
	}
	cout << ans << "\n";
}
