#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main() {
	while (true) {
		int n;
		int s[1001];
		double m = 0.0f;
		double a = 0.0f;

		cin >> n;
		if (n == 0)break;

		for (int i = 0; i < n; i++) {
			cin >> s[i];
			m += s[i];
		}
		m /= n;

		for (int i = 0; i < n; i++) {
			a += (s[i] - m)*(s[i] - m);
		}
		a = sqrt(a / n);

		printf("%lf\n", a);
	}
}