#include <iostream>
#include <cmath>
using namespace std;
#define EPS 1e-9

double get_distance( double x1, double y1, double x2, double y2 )
{
	return sqrt( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
}

double get_sum( double x1, double y1, double x2, double y2, double x3, double y3 )
{
	double a = get_distance( x1, y1, x2, y2 );
	double b = get_distance( x2, y2, x3, y3 );
	double c = get_distance( x3, y3, x1, y1 );
	double s = ( a + b + c ) / 2;
	return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );
}

int main( void )
{
	double x1, y1, x2, y2, x3, y3, xp, yp;
	while ( cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp )
	{
		double s = get_sum( x1, y1, x2, y2, x3, y3 );
		double s1 = get_sum( x1, y1, xp, yp, x2, y2 );
		double s2 = get_sum( x2, y2, xp, yp, x3, y3 );
		double s3 = get_sum( x3, y3, xp, yp, x1, y1 );

		if ( fabs( s - ( s1 + s2 + s3 ) ) <= EPS ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}