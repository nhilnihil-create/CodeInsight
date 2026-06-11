#include <bits/stdc++.h>

#define debug(a) cout << #a << " " << a << endl;
#define _debug(a, i) cout << #a << "[" << i << "]" \
						  << " = " << a[i] << endl;
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define PI 3.141592654
#define all(v) v.begin(), v.end()

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
using pi = pair<int, int>;

ll powmod(ll base, ll exp, const ll MOD) { ll ans = 1; while (exp) { if (exp & 1)	ans = (ans * base) % MOD; base = (base * base) % MOD; exp >>= 1; }return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll modInverse(ll n, const ll p) { return powmod(n, p - 2, p); }

//ll f[500005];
//ll kCn(ll k, ll n) { return (f[n] * modInverse((f[n - k] * f[k]) % MOD, MOD)) % MOD; }


const int mxN = 1e6;


void test_case() {
	
}

int main() {
	fastio;
	int l, r, d;
	cin >> l >> r >> d;
	int ans = 0;
	for (int i = l; i <= r; ++i)
		ans += (i % d == 0);
	cout << ans;
	return 0;
}
