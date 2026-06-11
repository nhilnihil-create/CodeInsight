#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const double PI = 3.14159265359;

int main() {
	double a, b, x;
	cin >> a >> b >> x;	
	x = x / a;
	if (x <= a * b / 2) {
		a = 2 * x / b;
	}
	else {
		x = a * b - x;
		b = 2 * x / a;
	}
	double rad = atan2(b, a);
	double angle = rad / PI * 180.0;
	printf("%.10f\n", angle);
	return 0;
}