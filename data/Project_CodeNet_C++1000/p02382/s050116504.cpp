#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double minkdist( vector<double> x, vector<double> y, double p, int n )
{
	double res = 0;

	if( p == 0 ) {
		vector<double>z( 0 );
		for( int i =0; i < n; i++ ) {
			z.push_back( abs( x[ i ] - y[ i ] ) );
		}
		res = *max_element( z.begin(), z.end() );
	}
	else {
		for( int i = 0; i < n; i++ ) {
			res += pow( abs( x[ i ] - y[ i ] ), p );
		}
		res = pow( res, 1 / p );
	}

	return res;
}

int main()
{

	vector<double> x( 0 ), y( 0 );

	int n;
	cin >> n;

	double tmp;
	for( int i = 0; i < n; i++ ) {
		cin >> tmp;
		x.push_back( tmp );
	}
	for( int i = 0; i < n; i++ ) {
		cin >> tmp;
		y.push_back( tmp );
	}

	cout << fixed;

	double sum = 0;
	sum = minkdist( x, y, 1, n );
	cout << sum << endl;

	sum = minkdist( x, y, 2, n );
	cout << sum << endl;

	sum = minkdist( x, y, 3, n );
	cout << sum << endl;

	sum = minkdist( x, y, 0, n );
	cout << sum << endl;
	return 0;
}