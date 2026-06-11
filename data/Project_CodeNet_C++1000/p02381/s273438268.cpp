#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n, *s;
	double m, a, aa;
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		s = new int[n];
		m = a = aa = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			m += s[i];
		}
		m /= n;
		for (int i = 0; i < n; i++)
			aa += pow(s[i] - m, 2);
		aa /= n;
		a = sqrt(aa);
		printf("%.8f\n", a);
		delete[] s;
	}
	return 0;
}