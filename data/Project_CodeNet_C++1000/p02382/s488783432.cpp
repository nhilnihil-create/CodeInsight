#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	long n;
	cin >> n;
	vector<double> x(n);
	for (long i = 0; i < n; i++){
		cin >> x[i];
	}
	vector<double> y(n);
	for (long i = 0; i < n; i++){
		cin >> y[i];
	}
	double one = 0;
	for (long i = 0; i < n; i++){
		one += abs(x[i] - y[i]);
	}
	cout << fixed << one << endl;
	double two = 0;
	for (long i = 0; i < n; i++){
		two += pow(abs(x[i] - y[i]), 2);
	}
	two = sqrt(two);
	cout << fixed << two << endl;
	double three = 0;
	for (long i = 0; i < n; i++){
		three += pow(abs(x[i] - y[i]), 3);
	}
	three = pow(three, 1.0/3.0);
	cout << fixed << three << endl;
	double inf = 0;
	for (long i = 0; i < n; i++){
		if (abs(x[i] - y[i]) > inf) inf = abs(x[i] - y[i]);
	}
	cout << fixed << inf << endl;
	return 0;
}