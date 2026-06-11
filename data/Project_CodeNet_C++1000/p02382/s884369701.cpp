#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int n, i, 
		x[100] = {}, 
		y[100] = {};

	double d = 0.0,
		   diff[100] = {};

	cin >> n;
	for( i = 0; i < n; ++i ) cin >> x[i];
	for( i = 0; i < n; ++i ) cin >> y[i];
	for( i = 0; i < n; ++i ) diff[i] = (double)abs( x[i] - y[i] );
	for( i = 0; i < n; ++i ) d += diff[i];

	cout << fixed << setprecision(5) << d << "\n";

	d = 0;
	for( i = 0; i < n; ++i )
		d += diff[i] * diff[i];
	d = sqrt( d );

	cout << fixed << setprecision(5) << d << "\n";

	d = 0;
	for( i = 0; i < n; ++i )
		d += pow( diff[i], 3.0 );
	d = pow( d, 1.0/3.0);

	cout << fixed << setprecision(5) << d << "\n";

	d = 0;
	for( i = 0; i < n; ++i )
		d = max( d, diff[i] );

	cout << fixed << setprecision(5) << d << "\n";

	return 0;
}