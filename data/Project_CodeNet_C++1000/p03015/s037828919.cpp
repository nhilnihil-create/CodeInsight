#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define pq priority_queue
#define bcnt(n) __builtin_popcountll(n)

using ll = long long;  // long longをllだけにした
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
using mlv = map<long long, vector<long long>>;

// 20200415
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a^{-1} mod を計算する
// modとaが互いに素のときのみ有効(数学的に逆元が一意に定まるのがそのときのみ)

int main() {
	ll const mod = 1e9 + 7;
	string l;
	cin >> l;
	ll n = l.size();
	vll v(n);
	rep(i, n) v[i] = l[i] - '0';
	ll res = 0;
	ll k = 0;
	rep(i, n) {
		if(v[i] == 0) continue;
		res += modpow(2, k, mod) * modpow(3, n - 1 - i, mod);
		res %= mod;
		k++;
	}
	res += modpow(2, k, mod);
	res %= mod;
	cout << res << endl;
}
