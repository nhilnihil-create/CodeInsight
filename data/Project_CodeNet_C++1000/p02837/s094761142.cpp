// type a
//a...AC狙い
//b...自信がない
//c...お試し
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

int n;
vector<vector<pair<int, int>>> d;
void input() {
	cin >> n;
	d.resize(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		d[i].resize(x);
		for (int j = 0; j < x; j++) {
			int y; cin >> y;
			int z; cin >> z;
			d[i].push_back({ y,z });
		}
	}
	return;
}
bool s[20];
int ans;
int cnt;
int solve() {
	ans = 0;
	for (int a = 0; a < (1 << n); a++) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((a >> i) & 1) {
				s[i] = 1;
				cnt++;
			}
			else 
				s[i] = 0;
		}
		bool h = true;
		for (int i = 0; i < n; i++) {
			if (s[i]) {
				for (int j = 0; j < (int)d[i].size(); j++) {
					if (s[d[i][j].first - 1] != (bool)d[i][j].second) {
						h = false;
						goto kaage;
					}
				}
			}
		}
		if (h) 
			ans = max(ans, cnt);
	kaage:;
	}
	return ans;
}

int main(void) {
	input();
	printf("%d\n", solve());

	return 0;
}