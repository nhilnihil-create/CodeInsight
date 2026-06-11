#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
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
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
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
using ll = long long;
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
#define INF (lint)10000000000000000
#define mod = (int)1000000007;
#pragma endregion
lint n;
vector<pair<lint,lint> > prime_factorize(lint N) {
	vector<pair<lint, lint>> res;
	for (lint a = 2; a * a <= N; a++) {
		if (N % a != 0) continue;
		lint ex = 0; 
		while (N % a == 0) {
			ex++;
			N /= a;
		}
		res.push_back({ a, ex });
	}
	if (N != 1) res.push_back({ N, 1 });
	return res;
}
void input() {
	cin >> n;
	return;
}
int ans = 0;
void solve() {
	vector<pair<lint, lint>> d;
	d = prime_factorize(n);
	int cnt = 0;
	for (int i = 0; i < d.size(); i++) {
		auto s = d[i];
		for (int j = 1; j < INF; j++) {
			cnt += j;
			if (cnt > s.second) {
				ans += j - 1;
				cnt = 0;
				break;
			}
		}
	}
}

int main(void) {
	input();
	solve();
	printf("%d\n", ans);

	return 0;
}