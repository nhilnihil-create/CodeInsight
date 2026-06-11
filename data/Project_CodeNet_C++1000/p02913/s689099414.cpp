#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
#include <limits.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m - 1; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v, n) reverse(v, v + n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout << (x) << '\n'
#define pe(x) cout << (x) << " "
#define DEBUG(x) cout << #x << ": " << x << endl
#define lb(v, n) lower_bound(v.begin(), v.end(), (n))
#define ub(v, n) upper_bound(v.begin(), v.end(), (n))
//#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i, v.size()) cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template <typename T1, typename T2> inline void chmin(T1& a, T2 b) {
	if (a > b) a = b;
}
template <typename T1, typename T2> inline void chmax(T1& a, T2 b) {
	if (a < b) a = b;
}
typedef pair<int, int> pii;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
uint32_t getrand() {
	uint32_t seed = time(NULL);
	mt.seed(seed);
	return mt();
}
// constexpr ll MOD = 1e9 + 7;
constexpr int MAX = 2000020;
const double pi = acos(-1);
constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;
void y(bool c) {
	if (c)
		print("Yes");
	else
		print("No");
}
using ul = unsigned long long;
constexpr ul MASK30 = (1ULL << 30) - 1;
constexpr ul MASK31 = (1ULL << 31) - 1;
constexpr ul MOD = (1ULL << 61) - 1;
constexpr ul MASK61 = MOD;
// mod 2^61-1を計算する関数
ul CalcMod(ul x) {
	ul xu = x >> 61;
	ul xd = x & MASK61;
	ul res = xu + xd;
	if (res >= MOD) res -= MOD;
	return res;
}
// a*b mod 2^61-1を返す関数(最後にModを取る)
ul Mul(ul a, ul b) {
	ul au = a >> 31;
	ul ad = a & MASK31;
	ul bu = b >> 31;
	ul bd = b & MASK31;
	ul mid = ad * bu + au * bd;
	ul midu = mid >> 30;
	ul midd = mid & MASK30;
	return (au * bu * 2 + midu + (midd << 31) + ad * bd);
}

struct RollingHash {
	vector<ul>hash, p;
	ul B;
	RollingHash(const string& s, ul B_) : B(B_) {
		int N = s.size();
		hash.assign(N + 1, 0);
		p.assign(N + 1, 1);
		for (int i = 0; i < N; i++) {
			hash[i + 1] = CalcMod(Mul(hash[i], B) + s[i]);
			p[i + 1] = CalcMod(Mul(p[i], B));
		}
	}

	ul find(int l, int r) { return CalcMod(hash[r] + MOD * 3 - Mul(hash[l], p[r - l])); }
};

void solve() {
	ul base = getrand() % 100007;
	int N;
	string S;
	cin >> N >> S;
	RollingHash rh(S, base);
	ll ok = 0, ng = N / 2 + 1;
	while (ng - ok > 1) {
		int mid = (ok + ng) / 2;
		bool possible = false;
		REP(i, N - 2 * mid + 1) {
			FOR(j, i + mid, N - mid + 1) {
				if (rh.find(i, i + mid) == rh.find(j, j + mid)) {
					possible = true;
					goto END;
				}
			}
		}
	END:;
		if (possible)
			ok = mid;
		else
			ng = mid;
	}
	print(ok);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	// int q; cin >> q;
	// while (q--)
	solve();
}
