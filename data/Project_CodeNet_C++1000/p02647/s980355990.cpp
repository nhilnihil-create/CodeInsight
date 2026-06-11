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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	forn(i, n) {
		cin >> a[i];
	}
	if (k >= n) {
		forn(i, n) {
			cout << n << " ";
		}
		cout << "\n";
		return 0;
	}
	int cnt = 0;
	bool changes = 1;
	while (changes && cnt < k) {
		bool f = 0;
		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			int l = max(0ll, i - a[i]), r = min(i + a[i], n - 1);
			b[l]++;
			if (r + 1 < n) {
				b[r + 1]--;
			}
		}
		int bal = 0;
		forn(i, n) {
			bal += b[i];
			if (bal != a[i]) {
				f = 1;
			}
			a[i] = bal;
		}
		cnt++;
		if (!f) {
			changes = 0;
		}
	}
	forn(i, n) {
		cout << a[i] << " ";
	}
	cout << "\n";
 	return 0;
}