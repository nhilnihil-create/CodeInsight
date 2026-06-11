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
#pragma endregion

int main(void) {
	lint n, k; cin >> n >> k;
	vector<lint> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int r = mod;
	int l = 0;
	while (l + 1 < r) {
		int mid = (r + l) / 2;
		lint cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] + mid - 1) / mid - 1;
		}
		if (cnt > k) l = mid;
		else r = mid;
	}
	cout << r << endl;

	return 0;
}