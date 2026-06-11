#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
//#pragma warning(disable : 4996)

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#endif

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

#define REP(i, n) for (int i = 0; i < (n); ++i)
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
#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i, v.size()) cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template <typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template <typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 1e9 + 7;
constexpr int MAX = 500050;
const double pi = acos(-1);
constexpr double EPS = 1e-8;
constexpr ll LINF = 1e18 + 1;
constexpr int INF = 1e9 + 1;

int dp[1000010][2];
string S;
int N;
bool done[1000010][2];
int rec(int i, bool flag) {
	if (i == N) {
		return flag;
	}
	if (done[i][flag])return dp[i][flag];
	done[i][flag] = true;
	int num = (S[i] - '0') + flag;
	int res1=0,res2 = 0;
	if (num < 10) {
		//自分が払う
		res1 += num;
		res1 += rec(i + 1, false);
		//相手が払う
		res2 += 10 - num;
		res2 += rec(i + 1, true);
		return dp[i][flag] = min(res1, res2);
	}
	else {
		res1 = rec(i + 1, true);
		return dp[i][flag] = res1;
	}
}


void solve(){
	cin >> S;
	N = S.size();
	VREVERSE(S);
	print(rec(0, 0));
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//Eratosthenes();
	//VSORT(sosuu);
	//REP(_, 100)test();
	//cerr << "done" << endl;
	//int q;
	//cin >> q;
	//while (q--)
	solve();
}
