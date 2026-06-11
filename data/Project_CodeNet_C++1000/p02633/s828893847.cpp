#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926535897932384626433832795;

int main() {
	double X; cin >> X; X = X * PI / 180.0;
	double x = cos(0), y = sin(0), t = 0;
	int n = 1;
	while (!(fabs(x) < 1e-9 && fabs(y) < 1e-9)) {
		t += X;
		x += cos(t);
		y += sin(t);
		n++;
	}
	printf("%d\n", n);
}