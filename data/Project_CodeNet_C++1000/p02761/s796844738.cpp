#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
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
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
int main() {
	ll n, m;
	cin >> n >> m;
	vl a(m);
	vl b(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	vl ans(n, 0);
	ans[0] = 1;
	for (int i = 0; i < m; i++) {
		ans[a[i]-1] = b[i];
	}
	bool falg = true;
	for (int i = 0; i < m; i++) {
		if (ans[a[i]-1] == b[i]) {

		}
		else {
			falg = false;
		}
	}
	if (n >= 2) {
		if (ans[0] == 0) {
			falg = false;
		}
	}
	if (n == 1 && m == 0) {
		cout << 0 << endl;
	}
	else {
		if (falg) {
			for (int i = 0; i < n; i++) {
				cout << ans[i];
			}
		}
		else {
			cout << -1 << endl;
		}
	}
}