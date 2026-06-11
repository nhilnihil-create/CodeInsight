#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double max(double x, double y){
	return x > y ? x : y;
}

int main(){
	int n;
	cout << fixed << setprecision(8);
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	double d1, d2, d3, d4;
	d1 = 0; d2 = 0; d3 = 0; d4 = 0;
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}
	for (int i = 0; i < n; i++){
		d1 += abs(x[i] - y[i]);
		d2 += (x[i] - y[i]) * (x[i] - y[i]);
		d3 += abs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]));
		d4 = max(d4, abs(x[i] - y[i]));
	}
	cout << d1 << endl << sqrt(d2) << endl << pow(d3, 1.0 / 3) << endl << d4 << endl;
}
