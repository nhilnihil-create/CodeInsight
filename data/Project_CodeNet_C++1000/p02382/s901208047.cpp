#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


int main()
{
	int n;
	int x[100];
	double d1 = 0, d2 = 0, d3 = 0, dinf = -1;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> x[i];
	}

	for (int i = 0;i < n;i++) {
		int yi;
		cin >> yi;
		yi = abs(x[i] - yi);
		d1 += yi;
		d2 += yi * yi;
		d3 += yi * yi * yi;

		if (yi > dinf) {
			dinf = yi;
		}
	}

	d2 = sqrt(d2);
	d3 = pow(d3, 0.333333333333);

	printf("%lf\n%lf\n%lf\n%f\n", d1, d2, d3, dinf);

    return 0;
}

