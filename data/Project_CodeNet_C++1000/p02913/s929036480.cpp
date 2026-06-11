#include <bits/stdc++.h>
using namespace std;

class RollingHash_Mersenne {
	// RH (mod : 1UL << 61 - 1, base : random)
	// https://atcoder.jp/contests/abc141/submissions/16495886
	const unsigned long long MASK30 = (1ULL << 30) - 1;
	const unsigned long long MASK31 = (1ULL << 31) - 1;
	const unsigned long long MASK61 = (1ULL << 61) - 1;
	const unsigned long long MOD = MASK61;
	const unsigned long long base = rand() % (unsigned long long)1e5 + 3;
	const unsigned long long POSITIVIZER = MOD << 2;
	vector<unsigned long long> hash, power;

	// a * b と mod が等しい数を返す
	// 結果は (1UL << 63) + 3 - (1UL << 31) * 3 以下
	unsigned long long Mul(unsigned long long a, unsigned long long b) const {
		unsigned long long au = a >> 31;
		unsigned long long ad = a & MASK31;
		unsigned long long bu = b >> 31;
		unsigned long long bd = b & MASK31;
		unsigned long long mid = ad * bu + au * bd;
		unsigned long long midu = mid >> 30;
		unsigned long long midd = mid & MASK30;
		return au * bu * 2 + midu + (midd << 31) + ad * bd;
	}

	// mod 2^61-1を計算する
	unsigned long long CalcMod(unsigned long long x) const {
		unsigned long long xu = x >> 61;
		unsigned long long xd = x & MASK61;
		unsigned long long res = xu + xd;
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

	unsigned long long get(int l, int r) const { return CalcMod(hash[r] + POSITIVIZER - Mul(hash[l], power[r - l])); }

	unsigned long long connect(unsigned long long h1, unsigned long long h2, unsigned long long h2len) const { return CalcMod(Mul(h1, power[h2len]) + h2); }

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


int main() {
	int n;
	string s;
	cin >> n >> s;

	RollingHash_Mersenne rh(s);
	int res = 0;
	for(int i=0 ;i<n;i++) {
		for(int j=0;j< n;j++) {
			if(j <= i + res) continue;
			int a = rh.LCP(i, n, rh, j, n);
			//	cout << a << endl;
			res = max(res, min(a, j - i));
		}
	}
	cout << res << endl;
}