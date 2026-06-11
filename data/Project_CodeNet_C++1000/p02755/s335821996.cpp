//#pragma warning(disable:4996)
//#include <Windows.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;

template<class T>
inline void chmin(T& a, T b) {
	a = min(a, b);
}

template<class T>
inline void chmax(T& a, T b) {
	a = max(a, b);
}

void input();
void solve();

void daminput();

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	//daminput();
	solve();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

int A, B;

void input() {
	cin >> A >> B;
}

void daminput() {
}

void solve() {
	int af = (100 * A) / 8;
	int bf = 10*B;
	int as;
	if ((100 * (A + 1)) % 8 == 0) {
		as = 100 * (A + 1) / 8 - 1;
	}
	else {
		as = (100 * (A + 1)) / 8;
	}
	int bs = 10 * B + 9;
	int fl = max(af, bf);
	int se = min(as, bs);
	for (int x = max(1, fl); x <= se; x++) {
		if ((8 * x / 100 == A) && (1 * x / 10 == B)) {
			cout << x << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}