#include <bits//stdc++.h>
using namespace std;
typedef long double ld;
#define c(n) cout << fixed <<setprecision(10) << n << endl
#define pi acos(-1)
int main() {
	int a, b, x; cin >> a >> b >> x;ld d;
	if (2 * x > a * a * b)d = 2.0 *(b * a * a - x) / pow(a,3);
	else d = 1.0 * b * b * a / (2 * x);
	c((atan(d)) / pi * 180);
}