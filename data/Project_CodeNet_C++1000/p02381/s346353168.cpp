#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n;
	const int max_n = 1000;
	double a[max_n];
	while (cin >> n, n) {
		double s = 0.0;
		double sum = 0.0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		double m = sum / n;
		for (int i = 0; i < n; i++) {
			s += pow(a[i] - m, 2);
		}
		s /= n;
		s = sqrt(s);
		printf("%.6f\n", s);
	}
    return 0;
}