#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N, D, n, x, y;
	double r;
	n = 0; N = 0; D = 0;
	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		x = 0; y = 0;
		cin >> x >> y;
		r = 0;
		r = sqrt(pow(x,2) + pow(y,2));
		if (r <= D) {
			n += 1;
		}
		else {
			n += 0;
		}
	}
	cout << n << endl;
	return 0;
}