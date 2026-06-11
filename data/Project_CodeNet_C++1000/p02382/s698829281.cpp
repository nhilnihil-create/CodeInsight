#include <iostream>
#include <cmath>
#include <iomanip>

#define SIZE 100

using namespace std;

double Minkp1(int, double [], double []);
double Minkp2(int, double [], double []);
double Minkp3(int, double[], double[]);
double Minkpinf(int, double [], double []);

int main(void){
	int n;
	double x[SIZE], y[SIZE];
	double p1, p2, p3, pinf;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	p1 = Minkp1(n, x, y);
	p2 = Minkp2(n, x, y);
	p3 = Minkp3(n, x, y);
	pinf = Minkpinf(n, x, y);
	
	
	cout << fixed << setprecision(8);
	cout << p1 << "\n";
	cout << p2 << "\n";
	cout << p3 << "\n";
	cout << pinf << "\n";

	return 0;
}

double Minkp1(int n, double x[], double y[]) {
	double dist = 0.0;
	for (int i = 0; i < n; i++) {
		dist += abs(x[i] - y[i]);
	}
	return dist;
}


double Minkp2(int n, double x[], double y[]) {
	double dist = 0.0;
	for (int i = 0; i < n; i++) {
		dist += pow(x[i] - y[i], 2);
	}
	return sqrt(dist);
}


double Minkp3(int n, double x[], double y[]) {
	double dist = 0.0;
	for (int i = 0; i < n; i++) {
		dist += pow(abs(x[i] - y[i]), 3);
	}
	return pow(dist, 1.0/3.0);
}


double Minkpinf(int n, double x[], double y[]) {
	double dist = 0.0;
	double tmp = 0.0;
	for (int i = 0; i < n; i++) {
		tmp = abs(x[i] - y[i]);
		if (dist < tmp) {
			dist = tmp;
		}
	}
	return dist;
}