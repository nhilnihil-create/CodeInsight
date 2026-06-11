#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main( )
{
	int n;	
	cin>>n;
	
	vector<double> x(n), y(n);	
	double num;
	for( int i=0; i<n; i++ ) {
		cin>>num;
		x.at( i ) = num;
	}
	for( int i=0; i<n; i++ ) {
		cin>>num;
		y.at( i ) = num;
	}
	double Dxy, Dxy2, Dxy3, Dmax;
	Dxy = Dxy2 = Dxy3 = Dmax = 0;
	for( int i=0; i<n; i++ ) {
		num = fabs(  x.at( i ) - y.at( i ) );
		Dxy += num;
		Dxy2 += pow( num, 2 );
		Dxy3 += pow( num, 3 );
		Dmax = max( Dmax, num );
	}
	
	cout.setf( ios::fixed );
	cout<<Dxy<<endl;
	cout<<sqrt( Dxy2 )<<endl;
	cout<<cbrt( Dxy3 )<<endl;
	cout<<Dmax<<endl;
	
	return 0;
}