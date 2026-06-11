// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL _t1 = -1, _t2, _a1, _a2, _b1, _b2;
		cin >> _t1 >> _t2 >> _a1 >> _a2 >> _b1 >> _b2;
		if (_t1 < 0) return 0;
		LL t1 = _t1, t2 = _t2, a1 = _a1, a2 = _a2, b1 = _b1, b2 = _b2;
		LL p = (a1 - b1) * t1, q = (a2 - b2) * t2;
		if (p < 0) {
			p = -p, q = -q;
		}
		if (p + q == 0) {
			cout << "infinity" << endl;
		} else {
			LL ans = 0;
			if (p + q < 0) {
				LL r = p / -(p + q), s = p % -(p + q);
				ans = (LL)r * 2 + (s != 0);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
