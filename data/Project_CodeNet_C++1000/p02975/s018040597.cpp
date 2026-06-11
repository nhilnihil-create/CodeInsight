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

bool check(int n, map<ll, int> &t) {
	if (t.size() == 1) {
		if ((*t.begin()).first == 0) return true;
	}
	else if (t.size() == 2) {
		if (n % 3 != 0) return false;

		int zeroNum = (*t.begin()).second;
		int xNum = (*t.rbegin()).second;

		if ((*t.begin()).first != 0 && (*t.rbegin()).first == 0) swap(zeroNum, xNum);

		if (zeroNum == n / 3 && xNum == n * 2 / 3) return true;
		else return false;
	}
	else if (t.size() == 3) {
		if (n % 3 != 0) return false;

		int s = 0;
		for (auto p = t.begin(); p != t.end(); ++p) {
			if ((*p).second != n / 3) return false;
			s ^= (*p).first;
		}

		if(s == 0) return true;
		else return false;
	}

	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll* a = new ll[n];
	rep(i, n) cin >> a[i];

	map<ll, int> t;
	rep(i, n) ++t[a[i]];

	if (check(n, t)) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}
