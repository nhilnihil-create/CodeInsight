#include<iostream>
#include<complex>
using namespace std;
typedef complex<double> xy;

int main() {
	xy a, b, c, p;
	while (cin 
		>> a.real() >> a.imag()
		>> b.real() >> b.imag()
		>> c.real() >> c.imag()
		>> p.real() >> p.imag()) 
	{
		double d, e, f;
		d = (conj(a - p)*(b - p)).imag();
		e = (conj(b - p)*(c - p)).imag();
		f = (conj(c - p)*(a - p)).imag();
		if ((d < 0 && e < 0 && f < 0) || (d > 0 && e > 0 && f > 0))	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}