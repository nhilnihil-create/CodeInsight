#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define prec fixed << setprecision(12)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define test int t; cin >> t; while(t--)
#define inf 1e9+5
int fpow(int x, int y, int p = MOD) {x = x % p; int sum = 1; while (y) {if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;} return sum;}
int fact[1000007] = {0};
void facto() {fact[0] = 1; fact[1] = 1; for (int i = 2; i < 100007; i++)fact[i] = (fact[i - 1] * i) % MOD;}
int ncr(int n, int r) {int res = 1; res = fact[n]; res = (res * (fpow(fact[r], MOD - 2))) % MOD; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;}
int npr(int n, int r) {int res = 1; res = fact[n]; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;}
int modmul(ll x, ll y) {return (x * y) % MOD;}
int modadd(int x, int y) {return (x + y) % MOD;}
int modsub(int x, int y) {return (x - y + MOD) % MOD;}

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

void solve() {
	int n;
	cin >> n;
	vi v(n), b(n);
	rep(i, 0, n - 1) cin >> v[i];
	rep(i, 1, n - 1) {
		if (v[i] > v[i - 1])
			v[i]--;
	}
	rep(i, 0, n - 1) b[i] = v[i];
	sort(all(b));
	if (b == v) {
		cout << "Yes";
	} else {
		cout << "No";
	}
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