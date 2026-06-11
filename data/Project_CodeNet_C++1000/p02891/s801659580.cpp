// type a
//a...いけそう
//b...自信がない
//c...お試し
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

string s;
lint k;

int main(void) {
	cin >> s >> k;
	if ((int)s.size() == 1) {
		cout << (int)s.size() * k / 2 << endl; return 0;
	}
	for (int i = 0; i < (int)s.size() - 1; i++) {
		if (s[i] != s[i + 1]) 
			break;
		if (i == (int)s.size() - 2) {
			cout << (lint)s.size() * k / 2 << endl;
			return 0;
		}
	}
	if (s[0] != s[(int)s.size() - 1]) {
		lint ans = 0;
		int cnt = 1;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] == s[i - 1]) cnt++;
			else {
				ans += cnt / 2;
				cnt = 1;
			}
			if (i == (int)s.size() - 1 && cnt != 1) ans += cnt / 2;
		}
		cout << ans * k << endl;
	}
	else {
		lint a = 1;
		lint b = 1;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] == s[i - 1]) a++;
			else break;
		}
		for (int i = (int)s.size() - 1; i > 0; i--) {
			if (s[i] == s[i - 1]) b++;
			else break;
		}
		//
		lint ans = 0;
		lint cnt = 1;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] == s[i - 1]) cnt++;
			else {
				ans += cnt / 2;
				cnt = 1;
			}
			if (i == (int)s.size() - 1 && cnt != 1) ans += cnt / 2;
		}
		cout << ans * k - ((a / 2ll + b / 2ll - (a + b) / 2ll) * (k - 1)) << endl;
		return 0;
	}

	return 0;
}