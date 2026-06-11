#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
#include <array>
// ===============================================================
//using系
#pragma region header
using namespace std;
using lint = long long;
using ld = long double;
using ulint = unsigned long long;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr lint mod = 1000000007;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#define INF (lint)10000000000000000;
#define mod (int)1000000007
#pragma region header
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
#pragma endregion
#pragma endregion
lint gcd(lint a, lint b) {
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int n;
vector<int> d;
bool input() {
	cin >> n;
	d.resize(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (i == 0) cnt = d[0];
		else cnt = gcd(cnt, d[i]);
	}
	if (cnt != 1) return false;
	return true;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (!input()) { cout << "not coprime" << endl; return 0; }
	vector<bool> pn(1000010, true);
	for (int i = 2; i <= 1000005; i++) {
		if (pn[i]) {
			for (int j = 2 * i; j < 1000001; j += i) {
				pn[j] = false;
			}
		}
	}
	vector<int> p;
	for (int i = 2; i <= 1000005; i++) if (pn[i]) p.push_back(i);
	bool h = true;
	set<int> s;
	for (int i = 0; i < d.size(); i++) {
		while (1) {
			for (int j = 0; j < p.size(); j++) {
				if (p[j] * p[j] > d[i]) break;
				if (d[i] % p[j] == 0) {
					while (d[i] % p[j] == 0) {
						d[i] /= p[j];
					}
					if (s.count(p[j])) {
						h = false;
						goto Cyan;
					}
					else s.insert(p[j]);
				}
			}
			if (d[i] != 1) {
				if (s.count(d[i])) {
					h = false;
					goto Cyan;
				}
				else s.insert(d[i]);
			}
			break;
		}
	}
Cyan:;
	if (h) cout << "pairwise coprime" << endl;
	else cout << "setwise coprime" << endl;

	return 0;
}