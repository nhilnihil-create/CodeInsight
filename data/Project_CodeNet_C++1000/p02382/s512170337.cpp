#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int n, i, y,
		x[100] = {};

	double d[4] = {},
		   diff[100] = {};

	cin >> n;
	for( i = 0; i < n; ++i ) cin >> x[i];
	for( i = 0; i < n; ++i ){
		cin >> y;
		diff[i] = (double)abs( x[i] - y );
	}
	for( i = 0; i < n; ++i ) 
	for( i = 0; i < n; ++i ){
		d[0] += diff[i];
		d[1] += diff[i] * diff[i];
		d[2] += pow( diff[i], 3.0 );
		d[3] = max( d[3], diff[i] );
	}

	cout << fixed << setprecision(5) << d[0] << "\n";
	cout << fixed << setprecision(5) << sqrt(d[1]) << "\n";
	cout << fixed << setprecision(5) << pow( d[2], 1.0/3.0) << "\n";
	cout << fixed << setprecision(5) << d[3] << "\n";

	return 0;
}