#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define prec fixed << setprecision(12)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define test int t; cin >> t; while(t--)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

const int MAX = 3000000;
long long fac[MAX], finv[MAX], inv[MAX];

void pre() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

int c(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

void solve() {
	int x, y;
	cin >> x >> y;
	if ((x + y) % 3 != 0) {
		cout << 0 << endl;
		return;
	}
	int m = (2 * x) / 3 - y / 3;
	int n = x - 2 * m;
	pre();
	cout << c(n + m, n) << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// test
	solve();

	return 0;
}