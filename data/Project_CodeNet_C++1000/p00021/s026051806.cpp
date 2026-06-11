#include<iostream>
#include<complex>
#include<cmath>
using namespace std;
typedef complex<double> xy;

int main() {
	int n;
	xy a, b, c, d;
	double delta = 1e-11;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a.real() >> a.imag();
		cin >> b.real() >> b.imag();
		cin >> c.real() >> c.imag();
		cin >> d.real() >> d.imag();

		xy s = a - b, t = c - d;
		if (abs((conj(s)*t).imag()) < delta) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;

}