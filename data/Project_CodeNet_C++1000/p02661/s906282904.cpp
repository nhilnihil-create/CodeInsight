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
 
 
const int MAXN = 5e5 + 5;
const ll MOD = 998244353;
const ll INF = INT64_MAX;


random_device rd;
mt19937 rnd(rd());


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
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(all(a));
	sort(all(b));
	if (n % 2 == 1) {
		cout << b[n / 2 + 1] - a[n / 2 + 1] + 1 << "\n"; 
	} else {
		cout << b[n / 2] + b[n / 2 + 1] - a[n / 2] - a[n / 2 + 1] + 1 << "\n";
	}
 	return 0;
}