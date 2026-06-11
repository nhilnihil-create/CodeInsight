#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	int n, s[1000];
	double a, m;

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		m = 0;
		a = 0;

		for (int i = 0;i < n;i++) {
			cin >> s[i];
			m += s[i];
		}

		m /= n;

		for (int i = 0;i < n;i++)
			a += (s[i] - m)*(s[i] - m);

		a /= n;
		a = sqrt(a);
		printf("%f\n", a);
	}
	return 0;
}