#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, H, M;
	cin >> A >> B >> H >> M;

	double pi = acos(-1.0);

	double h = (H*60+M)/(12.0*60);
	// cout << h << endl;
	double m = M/60.0;
	h *= 2*pi;
	m *= 2*pi;

	double x1 = cos(h)*A, y1 = sin(h)*A;
	double x2 = cos(m)*B,  y2 = sin(m)*B;

	// cout << x1 << " " << y1 << endl;
	// cout << x2 << " " << y2 << endl;

	cout << fixed << setprecision(20);

	cout << hypot(x1-x2, y1-y2) << endl;
}