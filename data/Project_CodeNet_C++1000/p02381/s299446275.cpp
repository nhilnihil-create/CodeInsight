#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		int s[1000];
		double total = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			total += s[i];
		}

		double m = total / n;

		double a_2 = 0;
		for (int i = 0; i < n; i++) {
			a_2 += (s[i] - m)*(s[i] - m) / n;
		}

		double a = sqrt(a_2);
		printf("%.4f\n", a);
	}

	return 0;
}