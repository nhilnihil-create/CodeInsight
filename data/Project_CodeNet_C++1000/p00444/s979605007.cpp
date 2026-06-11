#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;
int main() {
	int n;
	int fh, h, fty, ten, f, i;
	int th = 1000;
	for (;;) {
		cin >> n;
		if (n == 0)break;
		th -= n;
		fh = th / 500;
		th -= 500 * fh;
		h = th / 100;
		th -= 100 * h;
		fty = th / 50;
		th -= 50 * fty;
		ten = th / 10;
		th -= 10 * ten;
		f = th / 5;
		th -= 5 * f;
		i = th;
		cout << fh + h + fty + ten + f + i << endl;
		th = 1000;
	}
	


}