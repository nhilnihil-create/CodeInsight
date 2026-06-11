#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#define BIT(nr) (1ULL << (nr))
#define int long long
#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

using rh_type = unsigned long long;

template <rh_type MOD = 0>
struct rolling_hash {
	int n;
	rh_type base;
	std::vector<rh_type> pow, hash;

	rolling_hash() {}

	template <typename Array>
	rolling_hash(const Array &s, rh_type b_ = 10007) {
		set(s, b_);
	}

	template <typename Array>
	void set(const Array &s, rh_type b_ = 10007) {
		n = s.size();
		base = b_;
		pow.resize(n + 1);
		pow[0] = 1;
		hash.resize(n + 1);
		hash[0] = 0;
		for (int i = 0; i < n; ++i) {
			if (MOD == 0) {
				pow[i + 1] = pow[i] * base;
				hash[i + 1] = s[i] + hash[i] * base;
			}
			else {
				pow[i + 1] = pow[i] * base % MOD;
				hash[i + 1] = (s[i] + hash[i] * base) % MOD;
			}
		}
	}

	rh_type get(int r) const { return hash[r]; }

	rh_type get(int l, int r) const {
		if (MOD == 0) {
			return get(r) - get(l) * pow[r - l];
		}
		else {
			return (get(r) - get(l) * pow[r - l] % MOD + MOD) % MOD;
		}
	}
};

// 1000000007, 1000000009, 1000000021, ...
using RH = rolling_hash<1000000007>;

using namespace std;

// 汎用的な二分探索のテンプレ(めぐる式)
int binary_search(function<bool(int)> isOk, int ng, int ok) {

	/* ok と ng のどちらが大きいかわからないことを考慮 */
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;

		if (isOk(mid)) ok = mid;
		else ng = mid;
	}
	return ok;
}

signed main() {
	int N;
	cin >> N;
	string S;
	cin >> S;

	RH hs(S);
	//RH hs2(S, 1919810);

	auto isOk = [&](int len) -> bool {
		map<rh_type, vector<int>> ma;

		rep(i, N - len + 1) {
			rh_type	hash = hs.get(i, i + len);
			ma[hash].push_back(i);
		}

		for (auto p : ma) {
			int f = p.second[0];
			int l = p.second.back();

			if (f + len <= l) {
				return true;
			}
		}
		return false;
	};

	cout << binary_search(isOk, N, 0) << "\n";

	return 0;
}
