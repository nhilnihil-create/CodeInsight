#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	int a, b, c, d, e, f = 0;
	cin >> a >> b;
	if (b > 21) {
		for (int i = 20; i < b; i += 10) {
			for (int j = 2; j < 10 && i + j <= b; j++) {
				c = i + j;
				d = c / 10;
				e = c % 10;
				//cout << a << "," << d * e << "," << e << endl;
				if (a >= d * e) {
					f++;
				}
			}
		}
	}
	cout << f;
	return 0;

}