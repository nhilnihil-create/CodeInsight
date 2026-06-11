#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

ll n;


int main ( void )
{
	cin >> n;
	for ( int i = sqrt ( n ) ; i >= 1 ; i-- ) {
			if ( n % i == 0 ) {
				cout << ( n / i ) + i - 2 << endl;
				break;
			}
	}
	return 0;
}