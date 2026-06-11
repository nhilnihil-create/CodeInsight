#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





















int main() {
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll cnt = 0;
	while (a >= b) {
		b *= 2;
		cnt++;
	}
	while (b >= c) {
		c *= 2;
		cnt++;
	}
	cout << ((cnt <= k) ? "Yes" : "No") << endl;
}