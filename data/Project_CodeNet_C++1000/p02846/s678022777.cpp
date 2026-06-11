#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long

int main() {
	LL t1, t2;
	LL a1, a2;
	LL b1, b2;

	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
		cout << "infinity" << endl;
		return 0;
	}
	LL res = 0;
	if (a1 > b1 && a2 > b2) {
		cout << 0 << endl;
		return 0;
	}
	if (a1 < b1 && a2 < b2) {
		cout << 0 << endl;
		return 0;
	}
	if (a1 > b1) {
		swap(a1, b1);
		swap(a2, b2);
	}
	// now a1 < b1, a2 > b2
	LL sa1 = a1 * t1, sa2 = a2 * t2;
	LL sb1 = b1 * t1, sb2 = b2 * t2;
	if (sa1 + sa2 < sb1 + sb2) {
		cout << 0 << endl;
		return 0;
	}
	// now sa1 + sa2 > sb1 + sb2
	LL ds = sb1 - sa1;
	LL dts = sa1 + sa2 - sb1 - sb2;
	LL ans = (ds / dts) * 2 + 1;
	if (ds % dts == 0) {
		ans -= 1;
	}
	cout << ans << endl;
	return 0;
}