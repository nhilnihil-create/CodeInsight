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

	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d >> s;


	bool ok = true;
	if (c > d) {
		REP(i, a, c - 1) {
			if (s[i] == '#' && s[i + 1] == '#') {
				ok = false;
				break;
			}
		}

		if (ok) {
			ok = false;
			REP(i, b - 2, d - 1) {
				if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
					ok = true;
					break;
				}
			}
		}
	}
	else {
		REP(i, a, c - 1) {
			if (s[i] == '#' && s[i + 1] == '#') {
				ok = false;
				break;
			}
		}

		if (ok) {
			REP(i, b, d - 1) {
				if (s[i] == '#' && s[i + 1] == '#') {
					ok = false;
					break;
				}
			}
		}
	}

	if (ok) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}
