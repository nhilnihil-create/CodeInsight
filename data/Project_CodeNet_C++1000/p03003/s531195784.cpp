#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <string>
#include <bitset>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
//typedef pair<ll, P> T;
typedef vector<ll> vec;
typedef vector<vec> mat;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define revrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define f first
#define s second
#define pb push_back

ll mod = 1000000007;
const ll INF = 100000000000010000;
//const ull B = 998244353;

//ll bit[200010];
//ll kai[3010];
//ll Cnt[10010];

//void pres(double A, ll x = 20) { printf("%.20f\n", x); }

vector<ll> dx = { 0, 1, 0, -1, 1, -1, 1, -1, 0};
vector<ll> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0};

void chmin(ll& x, ll y) {
	x = min(x, y);
}

void chmax(ll& x, ll y) {
	x = max(x, y);
}


/*ll sum(ll i)
{
	i += 1;
	ll t = 0;
	while (i > 0)
	{
		t += bit[i];
		i -= i & -i;
	}
	return t;
}

void add(ll i, ll x)
{
	i += 1;
	while (i <= 200005)
	{
		bit[i] += x;
		i += i & -i;
	}
}*/

/*`ll SAIKI(ll S) {
	for (ll T = S; ; T = (T - 1) & S) {

	}
}*/

mat mul(mat &mt_a, mat &mt_b) {
	mat mt_c(mt_a.size(), vec(mt_b[0].size()));
	rep(i, mt_a.size()) rep(k, mt_b.size()) rep(j, mt_b[0].size()) {
		mt_c[i][j] = (mt_c[i][j] + mt_a[i][k] * mt_b[k][j] % mod) % mod;
	}
	return mt_c;
}

mat pow_mat(mat mt_a, ll k) {
	mat mt_b(mt_a.size(), vec(mt_a.size()));
	rep(i, mt_a.size()) mt_b[i][i] = 1;
	while (k > 0) {
		if (k % 2) mt_b = mul(mt_b, mt_a);
		mt_a = mul(mt_a, mt_a);
		k /= 2;
	}
	return mt_b;
}

ll pow_long(ll x, ll y) {
	ll res = 1;
	while (y > 0) {
		if (y % 2 == 1) res *= x;
		x *= x;
		y /= 2;
	}
	return res;
}

void test() {
	cout << "888888888888888888888888" << endl;
}

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll pow_mod(ll x, ll k) {
	x %= mod;
	ll res = 1;
	while (k > 0) {
		if (k % 2) {
			res *= x; res %= mod;
		}
		x *= x; x %= mod;
		k /= 2;
	}
	return res;
}

ll div_mod(ll x) {
	return pow_mod(x, mod - 2);
}

vector <ll> par; // 各元の親を表す配列
vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

void init_u(ll sz_) {
	par.resize(sz_);
	siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
	for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
}

// Member Function
// Find
ll root(ll x) { // 根の検索
	while (par[x] != x) {
		x = par[x] = par[par[x]]; // x の親の親を x の親とする
	}
	return x;
}

// Union(Unite, Merge)
bool merge(ll x, ll y) {
	x = root(x);
	y = root(y);
	if (x == y) return false;
	// merge technique（データ構造をマージするテク．小を大にくっつける）
	if (siz[x] < siz[y]) swap(x, y);
	siz[x] += siz[y];
	par[y] = x;
	return true;
}

bool issame(ll x, ll y) { // 連結判定
	return root(x) == root(y);
}

ll size(ll x) { // 素集合のサイズ
	return siz[root(x)];
}


//コンビネーション
const int MAXcomb = 1000010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAXcomb; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
ll comb(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * finv[k] % mod * finv[n - k] % mod;
}


/*map<ll, ll> pres;
ll ct;

void makePrimeList(ll x) {
	ll X = x;
	for (ll j = 2; j * j <= x; j++) {
		ll cnt = 0;
		while (X % j == 0) {
			cnt++;
			X /= j;
		}
		if (cnt) {
			if (pres[j] == 0) {
				ct++;
				pres[j] = ct;
			}
			Cnt[pres[j]] += cnt;
		}
	}
	if (X != 1) {
		if (pres[X] == 0) {
			ct++;
			pres[X] = ct;
		}
		Cnt[pres[X]] += 1;
	}
}*/

ll dp[2010][2010];
ll N, M;
ll S[2010], T[2010];
ll tmp[2010];
ll ans;

void solve() {
	cin >> N >> M;
	rep(i, N) cin >> S[i];
	rep(i, M) cin >> T[i];
	dp[0][0] = 1;
	rep(i, N) {
		rep(j, M + 1) dp[i + 1][j] += dp[i][j], dp[i + 1][j] %= mod;
		rep(j, M + 1) tmp[j] = 0;
		tmp[0] = dp[i][0];
		rep(j, M) tmp[j + 1] = tmp[j] + dp[i][j + 1], tmp[j + 1] %= mod;
		rep(j, M) if (S[i] == T[j]) dp[i + 1][j + 1] += tmp[j], dp[i + 1][j + 1] %= mod;
	}
	rep(i, M + 1) ans += dp[N][i], ans %= mod;
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll T = 1;
	//cin >> T;
	rep(i, T) solve();
	ll N;
	cin >> N;
}