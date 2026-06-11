#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<numeric>
#include<limits>
#include <cstdint>
#include<stack>
#include<queue>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define rep2(N1,N2) for(ll i=0;i<N1;i++)for(ll j=0;j<N2;j++)
#define rep3(N1,N2,N3)for(ll i=0;i<N1;i++)for(ll j=0;j<N2;j++)for(ll k=0;k<N3;k++)
#define For(i,N) for(ll i=0;i<N;i++)
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define ml(N) ll N;cin>>N; 
void yn(bool b) {
	if (b)printf("yes\n");
	else printf("no\n");
}

void Yn(bool b) {
	if (b)printf("Yes\n");
	else printf("No\n");
}

void YN(bool b) {
	if (b)printf("YES\n");
	else printf("NO\n");
}

int ctoi(char c) {
	return c - '0';
}

ll kai(ll x) {
	ll a = 1;
	if (x <= 0)
		return 1;
	else {
		for (ll i = 0; i < x; i++)
			a = a * (i + 1);
		return a;
	}
}

ll rui(ll x, ll y) {
	ll a = 1;
	for (ll i = 0; i < y; i++)
		a = a * x;
	return a;
}
const int nmax = 150;
int cccc[nmax][nmax];
ll comb(ll n, ll k) {
	if (n < k) {
		cout << "error n<k" << endl;
		return -1;
	}
	if (cccc[n][k] > 0)return cccc[n][k];
	if (k == 0 || n == k)return 1;
	return cccc[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
}

ll keta(ll a) {
	ll i = 1;
	while (1) {
		if (a < pow((ll)10, i))
			return i;
		i++;
	}
}
vector<ll> v;
ll n, m;
//m進数全探索
ll inc(ll a = n - 1) {
	if (a == 0 && v[0] == m) {
		v[0] = -1;
		return v[0];
	}
	if (v[a] == m) {
		v[a] = 0;
		inc(a - 1);
		return v[a];
	}
	else {
		++v[a];
		return v[a];
	}
}

ll mod = 1e9 + 7;

ll modkai(ll a) {
	ll ret = 1;
	rep(a) {
		ret *= (i + 1);
		ret %= mod;
	}
	return ret;
}

ll modpowl(ll a, ll b) {
	if (b == 0) {

		return 1;
	}
	if (b == 1) {

		return a;
	}
	if (b >= 2) {
		if (b % 2 == 0) {
			ll c = modpowl((a*a) % mod, b / 2);
			c = c % mod;

			return c;
		}
		else {
			ll c = (modpowl((a*a) % mod, b / 2) % mod)*a;
			c = c % mod;

			return c;
		}
	}
}
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

ll llpow(ll a, ll b) {
	if (b == 0) {

		return 1;
	}
	if (b == 1) {

		return a;
	}
	if (b >= 2) {
		if (b % 2 == 0) {
			ll c = llpow((a*a), b / 2);
			c = c;

			return c;
		}
		else {
			ll c = (llpow((a*a), b / 2))*a;
			c = c;

			return c;
		}
	}
}
std::vector<ll> Eratosthenes(ll N)
{
	std::vector<bool> is_prime(N + 1);
	for (ll i = 0; i <= N; i++)
	{
		is_prime[i] = true;
	}
	std::vector<ll> P;
	for (ll i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			for (ll j = 2 * i; j <= N; j += i)
			{
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}
/*
ll modpower(ll a, ll r, ll mod) { //a^r
	ll x = 1;
	a %= mod;
	while (r > 0) {
		if (r & 1) x = x * a % mod;
		r >>= 1;
		a = a * a % mod;
	}
	return x;
}

ll modinv(ll a, ll mod) {
	return modpower(a, mod - 2, mod);
}


vector<ll> eval(vector<ll> &A, ll x, int depth, int K, int c, ll mod) {
	if (depth == K) {
		if (c < (int)A.size()) return { A[c] };
		else return { 0 };
	}
	ll xx = x * x%mod;
	vector<ll> even = eval(A, xx, depth + 1, K, c, mod);
	vector<ll> odd = eval(A, xx, depth + 1, K, c + (1 << depth), mod);
	ll m = 1 << (K - depth - 1);
	vector<ll> res(m * 2);
	ll y = 1;
	for (int i = 0; i < m; i++) {
		ll f1 = even[i], f2 = y * odd[i] % mod;
		res[i] = f1 + f2;
		if (res[i] >= mod) res[i] -= mod;
		ll im = i + m;
		res[im] = f1 - f2;
		if (res[im] < mod) res[im] += mod;
		y = y * x%mod;
	}
	return res;
}


vector<ll> Comvolution(vector<ll> &A, vector<ll> &B) {
	ll d = A.size() + B.size() - 1;
	ll K = 1;
	while ((1 << K) < d) K++;
	ll mod = 998244353;
	ll proot = modpower(31, 1 << (23 - K), mod);
	ll m = modinv(1 << K, mod);

	vector<ll> eval_a = eval(A, proot, 0, K, 0, mod);
	vector<ll> eval_b = eval(B, proot, 0, K, 0, mod);
	vector<ll> mul(1 << K, 0);
	for (int i = 0; i < (1 << K); i++) {
		mul[i] = eval_a[i] * eval_b[i] % mod;
	}
	vector<ll> res = eval(mul, modinv(proot, mod), 0, K, 0, mod);
	for (int i = 0; i < (1 << K); i++) {
		res[i] = res[i] * m % mod;
	}

	return res;
}
*/
double pi = acos(-1);
int main() {
	cout.precision(10);
	double a;
	double b;
	double x;
	cin >> a >> b >> x;
	double ki = a * b*a / 2;
	if (x >= ki) {
		double s = a * a*b - x;
		s /= a;
		double l = s * 2 / a;
		double sita = atan(l / a);
		sita *= 180;
		sita /= pi;
		cout << sita;
		return 0;
	}
	else {
		double s = x/a;
		double l = s * 2 / b;
		double sita = atan(l / b);
		sita *= 180;
		sita /= pi;
		cout << 90 - sita;
		return 0;
	}
}