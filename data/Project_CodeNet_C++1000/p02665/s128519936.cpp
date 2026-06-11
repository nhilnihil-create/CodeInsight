#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
using namespace std;
 

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define int long long

 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
 
const int MAXN = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;


random_device rd;
mt19937 rnd(rd());


int gcd(int a, int b) {
	return (!a ? b : gcd(b % a, a));
}


ll pw(ll a, ll x) {
	ll res = 1;
	while (x > 0) {
		if (x & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		x >>= 1;
	}
	return res;
}


signed main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	forn(i, n + 1) {
		cin >> a[i];
	}
	if (a[0] > 1) {
		cout << "-1\n";
		return 0;
	}
	b[0] = 1;
	for (int i = 1; i <= n; i++) {
		b[i] = (b[i - 1] - a[i - 1]) * 2;
		b[i] = min(b[i], INF);
		if (b[i] < a[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	int ans = 0, v = 0;
	for (int i = n; i >= 0; i--) {
		v += a[i];
		ans += min(v, b[i]);
	}
	cout << ans << "\n";
 	return 0;
}