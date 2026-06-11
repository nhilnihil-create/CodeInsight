#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
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
	//for (ll ii = 1; ii <= 100; ii++) {
	ll n ;//= ii ;
	cin >> n;
	//n--;
	vl bits(13, 0);
	ll dd = 1;
	ll cl = 0;
	while (dd <= n) {
		dd = dd * 26LL;
		cl++;
	}
	cl--;
	//cout << cl << "\n";
	int f = 0;
	for (ll i = cl; i >= 0; i--) {
		ll j = 1;
		for (ll k = 1; k <= i; k++)
			j = j * 26LL;
		ll cnt = 0;
		//f = 1;
		while (n >= j && cnt <= 25) {
			n = n - j;
			cnt++;
		}
		bits[i] = cnt;
		//cout << i << " " << cnt << "\n";
	}
	for (ll i = 0; i < cl; i++) {
		if (bits[i] <= 0) {
			bits[i] += 26;
			bits[i + 1]--;
		}
	}
	string s = "";
	for (ll i = cl; i >= 0; i--) {
		if (bits[i] <= 0)
			continue;
		//cout << bits[i] << "\n";
		s = s + (char)('a' + bits[i] - 1);
	}
	cout << s << "\n";
	//cout << 26 * 25 << "\n";
}//

