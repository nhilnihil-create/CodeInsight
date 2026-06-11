#include <iostream>
#include <complex>

using namespace std;

int main() {
	int n;
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		complex<double> a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
		complex<double> n(a - b), m(c - d);
		complex<double> r(n.real()*m.imag() - m.real()*n.imag());

		if (abs(r - 0.0) < 1e-10) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
}