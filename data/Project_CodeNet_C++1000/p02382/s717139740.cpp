// 2014/08/01 Tazoe

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int x[100];
	for(int i=0; i<n; i++){
		cin >> x[i];
	}

	int y[100];
	for(int i=0; i<n; i++){
		cin >> y[i];
	}

	double f[100];
	for(int i=0; i<n; i++){
		f[i] = fabs((double)x[i]-(double)y[i]);
	}

	double sum = 0.0;
	for(int i=0; i<n; i++){
		sum += f[i];
	}
	double d = sum;

	cout.precision(6);
	cout << fixed << d << endl;

	sum = 0.0;
	for(int i=0; i<n; i++){
		sum += (f[i]*f[i]);
	}
	d = sqrt(sum);

	cout << fixed << d << endl;

	sum = 0.0;
	for(int i=0; i<n; i++){
		sum += (f[i]*f[i]*f[i]);
	}
	d = pow(sum, 1.0/3.0);

	cout << fixed << d << endl;

	d = f[0];
	for(int i=1; i<n; i++){
		d = max(d, f[i]);
	}

	cout << fixed << d << endl;

	return 0;
}