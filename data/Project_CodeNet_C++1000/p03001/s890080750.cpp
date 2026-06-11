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
	double W, H, x, y, ans, z = 0;
	cin >> W >> H >> x >> y;

	ans = W * H / 2;

	if (x == W / 2 && y == H / 2) {
		z = 1;
	}

	cout << setprecision(15) << ans << " " << z;
	
	return 0;

}
