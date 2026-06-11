#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <limits>
#include <numeric>
#include <valarray>
#include <fstream>

using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i, a, n) for(LL i = (a), i##_max = (n); i < i##_max; ++i)
#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##min = (a); i >= i##min; --i)
#define ALL(arr) (arr).begin(), (arr).end()
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(NULL); ios::sync_with_stdio(false);}
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template<class T>
T Compare(T left, T right) { return left > right ? 1 : (left < right ? -1 : 0); }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }
template <class T>
T Next() { T buf; cin >> buf; return buf; }

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "BinaryMatrix.h"
#include "BIT.h"
#include "Factorization.h"
#include "FlowSolver.h"
#include "Graph.h"
#include "LazySegmentTree.h"
#include "Math.h"
#include "Matrix.h"
#include "MinMax.h"
#include "Position.h"
#include "Range.h"
#include "Rational.h"
#include "SegmentTree.h"
#include "SegmentTree2D.h"
#include "SuffixArray.h"
#include "Tree.h"
#include "UnionFind.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>> (istream& ist, __int128& val) { LL tmp;  ist >> tmp; val = tmp; return ist; }
ostream& operator<< (ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

#if 1234567891
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;
// template <class T>
// auto Is(const T& value) { return [value](const auto& comparand) -> bool { return comparand == value; }; }
#endif

int N;

void print(int a, int b) {
	cout << a << ' ' << b << endl;
}

void trip(int p, int a, int b) {
	print(p, a);
	print(a, b);
	print(p, N + b);
	print(N + b, N + a);
}

void sub() {
	int k = 1;
	while (k < N) {
		k *= 2;
	}
	if (N == k) {
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;

	k /= 2;
	if (N % 2 == 0) {
		if (N % 4 == 0) {
			vector<int> v = { k, N ^ k };
			REP(i, 1, N) {
				if (i == k || i == (N ^ k)) continue;
				v.push_back(i);
			}
			const int M = v.size();
			REP(i, 0, M) v.push_back(v[i] + N);

			REP(j, 1, v.size()) {
				print(v[j - 1], v[j]);
			}
			print(k, N);
			print(N ^ k, N + N);
		} else {
			vector<int> v = { 2, N - 1 };
			REP(i, 2, N) {
				if (i == 2 || i == N - 1) continue;
				v.push_back(i);
			}
			const int M = v.size();
			REP(i, 0, M) v.push_back(v[i] + N);

			REP(j, 1, v.size()) {
				print(v[j - 1], v[j]);
			}

			print(2, 1);
			print(1, N);
			print(N - 1, N + N);
			print(N + N, N + 1);
		}
	} else {
		for (int k = 2; k <= N; k += 2) {
			print(1, k);
			print(k, k + 1);
			print(1, N + k + 1);
			print(N + k + 1, N + k);
		}
		print(3, N + 1);
	}
}

int main() {
	cin >> N;
	sub();
	return 0;
}
