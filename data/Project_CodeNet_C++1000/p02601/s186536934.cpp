#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>
#include <cassert>

using ll = long long;
using ull = unsigned long long;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

constexpr ll NOT_SPECIFIED_VALUE_MIN = INT64_MIN;
constexpr ll NOT_SPECIFIED_VALUE_MAX = INT64_MAX;

int main() {
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll ans = 0;
	while (b <= a) {
		b *= 2;
		ans++;
	}
	while (c <= b) {
		c *= 2;
		ans++;
	}
	if (ans <= k) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
