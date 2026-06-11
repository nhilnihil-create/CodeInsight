#include <bits/stdc++.h>

#define debug(a) cout << #a << " " << a << endl;
#define _debug(a, i) cout << #a << "[" << i << "]" << " = " << a[i] << endl;
#define fastio ios_base::sync_with_stdio(false); \
			cin.tie(0);							 \
			cout.tie(0);
#define PI 3.141592654

using namespace std;

using ll = long long;
const int MOD = 998244353;
const ll INF = 1e18 + 9;

ll powmod(ll base, ll exp, const ll MOD) { ll ans = 1; while (exp) { if (exp & 1)	ans = (ans * base) % MOD; base = (base * base) % MOD; exp >>= 1; }return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll modInverse(ll n, const ll p) { return powmod(n, p - 2, p); }
void add(ll& x, ll v) { x = (x + v) % MOD; if (x < 0) x += MOD; }
//ll f[500005];
//ll kCn(ll k, ll n) { return (f[n] * modInverse((f[n - k] * f[k]) % MOD, MOD)) % MOD; }


void test_case() {

}

const int mxN = 3001;
ll dp[mxN][mxN];

int main() {
	fastio;
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	//#endif // !ONLINE_JUDGE
	int N, S;
	cin >> N >> S;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= S; ++j) {
			dp[i + 1][j] += 2 * dp[i][j];
			dp[i + 1][j] %= MOD;
			if (j + a[i] <= S) {
				dp[i + 1][j + a[i]] += dp[i][j];
				dp[i + 1][j + a[i]] %= MOD;
			}
			
		}
	}
	cout << dp[N][S];
	return 0;
}
