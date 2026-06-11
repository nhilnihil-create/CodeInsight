#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
class RollingHash_Mersenne {
	const ull MASK30 = (1ULL << 30) - 1;
	const ull MASK31 = (1ULL << 31) - 1;
	const ull MASK61 = (1ULL << 61) - 1;
	const ull MOD = MASK61;
	const ull base = rand() % (ull)1e5 + 3;
	const ull POSITIVIZER = MOD << 2;
	vector<ull> hash, power;

	// a * b と mod が等しい数を返す
	// 結果は (1UL << 63) + 3 - (1UL << 31) * 3 以下
	ull Mul(ull a, ull b) const {
		ull au = a >> 31;
		ull ad = a & MASK31;
		ull bu = b >> 31;
		ull bd = b & MASK31;
		ull mid = ad * bu + au * bd;
		ull midu = mid >> 30;
		ull midd = mid & MASK30;
		return au * bu * 2 + midu + (midd << 31) + ad * bd;
	}

	// mod 2^61-1を計算する
	ull CalcMod(ull x) const {
		ull xu = x >> 61;
		ull xd = x & MASK61;
		ull res = xu + xd;
		if(res >= MOD) res -= MOD;
		return res;
	}

   public:
	RollingHash_Mersenne(const string &s) {
		int sz = (int)s.size();
		hash.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for(int i = 0; i < sz; i++) {
			power[i + 1] = CalcMod(Mul(power[i], base));
			hash[i + 1] = CalcMod(Mul(hash[i], base) + s[i]);
		}
	}

	template <class T>
	RollingHash_Mersenne(const vector<T> &v) {
		int sz = (int)v.size();
		hash.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for(int i = 0; i < sz; i++) {
			power[i + 1] = CalcMod(Mul(power[i], base));
			hash[i + 1] = CalcMod(Mul(hash[i], base) + v[i]);
		}
	}

	ull get(int l, int r) const { return CalcMod(hash[r] + POSITIVIZER - Mul(hash[l], power[r - l])); }

	ull connect(ull h1, ull h2, ull h2len) const { return CalcMod(Mul(h1, power[h2len]) + h2); }

	// Longest Common Prefix
	int LCP(int l_this, int r_this, RollingHash_Mersenne &other, int l_other, int r_other) {
		int len = min(r_this - l_this, r_other - l_other);
		int low = 0, high = len + 1;
		while(high - low > 1) {
			int mid = (low + high) / 2;
			if(get(l_this, l_this + mid) == other.get(l_other, l_other + mid))
				low = mid;
			else
				high = mid;
		}
		return low;
	}
};

#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
	int n;
	string s;
	cin >> n >> s;

	RollingHash_Mersenne rh(s);
	int res = 0;
	rep(i, n) {
		rep(j, n) {
			if(j <= i + res) continue;
			int a = rh.LCP(i, n, rh, j, n);
			//	cout << a << endl;
			res = max(res, min(a, j - i));
		}
	}
	cout << res << endl;
}