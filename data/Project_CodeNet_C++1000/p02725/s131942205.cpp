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
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	vl ans(m, 0);
	for (int i = 0; i < m; i++) {
		if (i != m - 1) {
			ans[i] = max(abs(a[i] - a[i + 1]), abs(n - abs(a[i] - a[i + 1])));
		}
		else {
			ans[i] = max(abs(a[i] - a[0]), abs(n - (a[i] - a[0])));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << endl;
}