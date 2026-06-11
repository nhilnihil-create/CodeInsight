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

const long long MOD = 1000000007;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int* a;
	a = new int[n];
	rep(i, n) a[i] = s[i] - '1';
	int num[3] = {0};
	rep(i, n) ++num[a[i]];

	int g = 1;
	if (num[1] == 0) {
		g = 2;
		rep(i, n) a[i] = a[i] >> 1;
	}
	else {
		rep(i, n) a[i] %= 2;
	}

	int ans = 0;
	rep(i, n) {
		int r = n - 1 - i;
		int c = 1;
		if (a[i] == 1) {
			rep(j, 32) {
				if (((n - 1) & (1 << j)) == 0 && (r & (1 << j)) != 0) {
					c = 0;
					break;
				}
			}

			ans = ans ^ c;
		}
	}

	cout << ans * g << "\n";

	return 0;
}
