#include <iostream>
#include <cstdio>
#include <cmath>
#define N 1000
using namespace std;
main () {
	int n, s[N];
	while (cin >> n, n) {
		double m = 0, a = 0;
		for (int i=0; i<n; i++) {
			cin >> s[i];
			m += s[i];
		}
		m /= n;
		for (int i=0; i<n; i++) a += (s[i]-m)*(s[i]-m);
		a /= n;
		printf("%.6f\n", sqrt(a));
	}
}