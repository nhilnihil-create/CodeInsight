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
	ll x;
	cin >> x;
	if (x < 600)
		cout << 8 << endl;
	else if (x < 800)
		cout << 7 << endl;
	else if (x < 1000)
		cout << 6 << endl;
	else if (x < 1200)
		cout << 5 << endl;
	else if (x < 1400)
		cout << 4 << endl;
	else if (x < 1600)
		cout << 3 << endl;
	else if (x < 1800)
		cout << 2 << endl;
	else
		cout << 1 << endl;
}
