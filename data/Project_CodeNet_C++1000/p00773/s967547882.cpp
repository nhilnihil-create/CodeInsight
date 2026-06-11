#include <cstdio>
using namespace std;

int main() {
	int x, y, s;
	int a, b;
	int p, q, res;

	while (true) {
		scanf("%d%d%d", &x, &y, &s);
		if (x == 0 && y == 0 && s == 0) {
			break;
		}

		res = 0;
		for (a = 1;a < s;a++) {
			p = (100 + x)*a / 100;
			q = s - p;
			if (q > 0) {
				if ((int)100 * q / (100 + x) != (int)100 * (q + 1) / (100 + x)) {
					if ((int)100 * (q + 1) / (100 + x) == (double)100 * (q + 1) / (100 + x)) {
						b = 100 * q / (100 + x);
					}
					else {
						b = 100 * (q + 1) / (100 + x);
					}
					if ((int)a*(100 + y) / 100 + (int)b*(100 + y) / 100 > res) {
						res = (int)a*(100 + y) / 100 + (int)b*(100 + y) / 100;
					}
				}
			}
		}

		printf("%d\n", res);
	}

	return 0;
}