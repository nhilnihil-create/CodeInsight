#include<iostream>
#include<cmath>

using namespace std;

int main( )
{
	int n;
	int s[1001];
	double sum, m;
	
	cout.setf( ios::fixed );
	while( cin>>n ) {
		if( 0 == n ) { break; }

		sum = 0;
		for( int i=0; i<n; i++ ) {
			cin>>s[i];
			sum += s[i];
		}
		m = sum / n;
		sum = 0;
		for( int i=0; i<n; i++ ) {
			sum += pow( s[i]-m , 2 );
		}
		cout<<sqrt( sum/n )<<endl;
	}
		
	return 0;
}