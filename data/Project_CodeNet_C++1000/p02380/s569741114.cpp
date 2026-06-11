#include<iostream>
#include<cmath>

using namespace std;

int main( )
{
	double a, b, C;

	cin>>a>>b>>C;
	
	double radianC = ( C * M_PI )/180.0;
	double h = sin( radianC ) * b;
	double S = a * h * 0.5;
	
	double L = sqrt( pow( ( a-( cos( radianC ) * b ) ), 2 ) + pow( h, 2 ) );
	L = L + a + b;
	
	
	cout.setf( ios::fixed );
	cout<<S<<'\n'<<L<<'\n'<<h<<'\n';
		
	return 0;
}