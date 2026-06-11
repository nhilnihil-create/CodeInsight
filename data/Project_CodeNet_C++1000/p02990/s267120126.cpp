#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using pq = priority_queue<int>;
template<class T>
using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int under = (1 << 31);
int upper = under - 1;
ll UNDER = (1LL << 63);
ll UPPER = UNDER - 1;
const int MOD = 1e9 + 7;
const long double pi = 3.141592653589793;
ll fac[110000];
ll finv[110000];
ll inv[110000];
void modinv(int max) {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < max; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll comb(int n, int r) {
	if (n < r) return 0;
	if (n < 0 || r < 0) return 0;
	return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}
int main() {
	modinv(10000);
	int n, k;
	cin >> n >> k;
	rep1(i, k) {
		ll blue = comb(k - 1, i - 1);
		ll red = comb(n - k + 1, i);
		ll ans = blue * red % MOD;
		cout << ans << endl;
	}
	return 0;
}