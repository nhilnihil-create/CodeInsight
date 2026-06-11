#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int x[10], y[10];
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	double sum = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			// cout << i << " " << j << "\n";
			sum += sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
	}
	int factorial = 1;
	for (int i = 1; i <= N; i++) {
		factorial *= i;
	}
	// cout << factorial << "\n";
	printf("%.10lf\n", (factorial / N / (N - 1)) * (N - 1) * 2 * sum / factorial);
	return 0;
}
