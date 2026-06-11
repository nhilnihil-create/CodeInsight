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
using namespace std;
using lint = long long;
using ld = long double;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
#pragma endregion

const lint INF = 1ll << 60;
const int mod = 1000000007;
vector<string> ans;

int n;

void solve(string s) {
	char c = 'a';
	int cnt = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] > c) c += (char)1, cnt++;
    }
	if (s.length() < n) {
		for (int i = 0; i <= cnt; i++) {
			string t = s;
			t += (char)'a' + (char)i;
			ans.emplace_back(t);
			solve(t);
		}
	}
	return;
}

int main(void) {
	cin >> n;
	if (n == 1) cout << 'a' << endl;
	solve("a");
	for (int i = 0; i < ans.size(); i++)
		if (ans[i].length() == n) cout << ans[i] << endl;

	return 0;
}