#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

using namespace std;

const long long MOD = 998244353;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll s;
	cin >> s;
	ll x, y, t = 1e9;
	x = (t - s % t) % t;
	y = (s + x) / t;
	char space = ' ';
	cout << 0 << space << 0 << space << t << space << 1 << space << x << space << y << "\n";

	return 0;
}
