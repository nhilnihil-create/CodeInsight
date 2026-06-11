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
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

signed main() {
	ll a, b, v, w, t;
	cin >> a >> v >> b >> w >> t;
	if (v > w) {
		if (abs(a - b) <= t * (v - w)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}