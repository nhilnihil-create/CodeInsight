#include <iostream>
#include <cmath>
#include <iomanip>

#define SIZE 1000

using namespace std;

double mean(int, double []);
double stdDev(int, double []);

int main(void){
	int n;
	double point[SIZE], stdD;
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> point[i];
		}
		stdD = stdDev(n, point);
		cout << fixed << setprecision(8);
		cout << stdD << "\n";
	}

	return 0;
}

double mean(int n, double p[]) {
	double sum =0.0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
	}
	return sum / (double)n;
}

double stdDev(int n, double p[]) {
	double mean_ = mean(n, p);
	double stdD = 0.0;
	for (int i = 0; i < n; i++) {
		stdD += pow(p[i] - mean_, 2);
	}
	return sqrt(stdD / (double)n);
}