#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;


int main() {

	ll L, R, ans = 2018;

	cin >> L >> R;

	if (R - L >= 2019) {
		ans = 0;
	}
	else {
		repl(i, L, R) {
			repl(j, L+ 1, R + 1) {
				ans = min(i * j % 2019, ans);
			}
		}
	}

	cout << ans;

	return 0;

}
