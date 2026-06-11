#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;

		int col[1000];
		int s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			col[i] = s;
		}
		
		double m = 0;
		for (int i = 0; i < n; i++) {
			m += col[i];
		}

		double na2 = 0;
		for (int i = 0; i < n; i++) {
			na2 += pow(col[i] - m/n, 2);
		}

		printf("%lf\n", sqrt(na2 / n));
	}
	return 0;
}
