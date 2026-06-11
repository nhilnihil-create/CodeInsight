#include<iostream>
#include<iomanip>
#include<complex>
#include<cmath>
using namespace std;
typedef complex<double> xy_t;

void kock(int, xy_t, xy_t);
void print(xy_t);
int main() {
	int n;
	cin >> n;
	xy_t p1(0,0), p2(100,0);
	print(p1);
	kock(n, p1, p2);
	print(p2);
}

void kock(int n, xy_t p1, xy_t p2) {
	if (n == 0) return;
	xy_t s, t, u;
	s = (p1 * xy_t(2,0) + p2) / xy_t(3.0,0);
	t = (p1 + p2 * xy_t(2,0)) / xy_t(3.0,0);
	u = s + (t - s)* xy_t(cos(M_PI / 3.0), sin(M_PI / 3.0));


	kock(n - 1, p1, s);
	print(s);
	kock(n - 1, s, u);
	print(u);
	kock(n - 1, u, t);
	print(t);
	kock(n - 1, t, p2);
}

void print(xy_t z) {
	cout << fixed << setprecision(6) << z.real() << " " << z.imag() << endl;
}