#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
	
#define int long long
#define double long double 
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "paintbarn"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

using namespace std;

const int INF = 4e18 + 10;
const int INF2 = 2e18 + 10;
const int INF3 = 2e10;
const int MAXN = 305;
const int LOGN = 19;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
const int MULT = 2e5;
const int MCNST = MOD * MOD * 8;

int32_t main() {
	FAST;

	int a, b, c;
	cin >> a >> b >> c;
	int c1 = 0, c2 = 0;
	while (a >= b) {
		c1++; b *= 2;
	}
	while (b >= c) {
		c2++; c *= 2;
	}
	int k;
	cin >> k;
	if (c1 + c2 <= k) cout << "Yes";
	else cout << "No";
}