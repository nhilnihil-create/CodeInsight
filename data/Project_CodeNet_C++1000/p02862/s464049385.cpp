#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

// ax+by=gcd(a,b)の解(x,y)を求める
ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a/b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

#define MAX_P 1000001
ll fact[MAX_P];	// n! mod p のテーブル O(p)

void make_fact(ll p) {
	ll n, wp;
	for (ll i = 0; i < MAX_P; i++) {
		if (i == 0) n = 1;
		else n = (n * i) % p;
		fact[i] = n;
	}
}

// n!=a p^eとしたときのa mod pを求める。O(log_p n)
ll mod_fact(ll n, ll p, ll& e) {
	e = 0;
	if (n == 0) return 1;

	// pの倍数の部分を計算
	ll res = mod_fact(n/p, p, e);
	e += n / p;

	// (p-1)!≡-1なので,(p-1)!^(n/p)はn/pの偶奇だけで計算できる
	if (n/p % 2 != 0) return res * (p - fact[n%p]) % p;
	return res * fact[n%p] % p;
}

// nCk mod pを求める。O(log_p n)
ll mod_comb(ll n, ll k, ll p) {
	if (n < 0 || k < 0 || n < k) return 0;
	ll e1, e2, e3;
	ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n-k, p, e3);
	if (e1 > e2 + e3) return 0;
	return a1 * mod_inverse((a2*a3)%p, p) % p;
}

int main() {
	ll x, y; cin >> x >> y;
	make_fact(MOD);
	ll ax, ay;
	ax = x;
	while(1) {
		ll tmp = 2 * ax;
		if (y == tmp) {
			if (ax == x) {
				ay = 0; break;
			}
		}
		if (tmp < y){
			ay = y - tmp;
			if (ax + ay * 2 == x) {
				break;
			}
		}
		if (ax == 0) {
			ax = -1; ay = -1; break;
		} else if (ax == 1) {
			ax = 0;
		} else {
			ax -= 2;
		}
	}
	if (ax == -1 && ay == -1) {
		cout << "0" << endl; return 0;
	}
	ll ret = mod_comb(ax+ay, ax, MOD);
	cout << ret << endl;
}