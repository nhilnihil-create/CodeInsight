#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>

using namespace std;

const double eps = 1e-12;

double cross(complex<double> a, complex<double> b) {
    return a.real() * b.imag() - a.imag() * b.real();
}

int main() {
    complex<double> t1, t2, t3, p;
    while(cin >> t1.real() >> t1.imag() >> t2.real() >> t2.imag() >> t3.real() >> t3.imag() >> p.real() >> p.imag()) {
        int plus = 0;
        if (cross(t1 - p, t2 - t1) > 0)plus++;
        if (cross(t2 - p, t3 - t2) > 0)plus++;
        if (cross(t3 - p, t1 - t3) > 0)plus++;
        if (plus == 3 || plus == 0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}