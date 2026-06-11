//X3, Y3 = (0, 0)とおいて、X1Y2 - X2Y1 = Sを目指す.
//ピンとこないので、具体例を試す。
//S = 10^9なら簡単で、10^9・1 - 0・0 = 10^9
//S = 10^9 + 7なら、  10^9・2 - 1・(10^9-7) = 10^9 + 7
//
//S = Q * 10^9 + R (Rは余り）とおく
//X1 = 10^9, Y2 = Q + 1, X2 = 1, Y1 = 10^9 - Rとしてみると、面積はちょうどSになる。
//S = 10^18のとき、Q + 1が10^9 + 1になるので注意。
//このときは、10^9・10^9 - 1・0 = 10^18にすればOK。
#include <iostream>
#define int long long
using namespace std;

signed main() {
	int s;
	cin >> s;
	
	int m = 1e+9;
	int q = s / m;
	int r = s % m;
	
	int x1 = m;
	int y2 = q + 1;
	int x2 = 1;
	int y1 = m - r;
	
	if (y2 > m) {
		y2--;
		y1 -= m;
	}
	
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << 0 << " " << 0 << endl;
	cerr << "area = " << x1 * y2 - x2 * y1 << endl;
	return 0;
}