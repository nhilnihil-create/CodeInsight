#include <iostream>
#include <complex>
#include <iomanip>

using namespace std;

int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	
	complex<double> s(a, b), t(c, d);
	
	cout << fixed << setprecision(10) << sqrt(norm(s - t)) << '\n';
	
	return 0;
}
