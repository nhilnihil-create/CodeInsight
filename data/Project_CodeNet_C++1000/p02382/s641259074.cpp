#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x[n], y[n];
	for(int i = 0; i < n; ++i){
		cin >> x[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> y[i];
	}
	double d = 0.0;
	for(int i = 0; i < n; ++i){
		d += abs(x[i] - y[i]);
	}
	cout << setprecision(10) << d << endl;
	d = 0.0;
	for(int i = 0; i < n; ++i){
		d += (x[i] - y[i]) * (x[i] - y[i]);
	}
	cout << sqrt(d) << endl;
	d = 0.0;
	for(int i = 0; i < n; ++i){
		d += pow(abs(x[i] - y[i]), 3);
	}
	cout << cbrt(d) << endl;
	double m = 0.0;
	for(int i = 0; i < n; ++i){
		if(m < abs(x[i] - y[i])) m = abs(x[i] - y[i]);
	}
	cout << m << endl;
	return 0;
}