#include<iostream>
using namespace std ;
int main()
{
	short num ;
	short suu[ 30 ] = { 0 } ;
	short i ;
	for( i = 0 ; i < 28 ; i++ )
	{
		cin >> num ;
		suu[ num - 1 ]++ ;
	}
	for( i = 0 ; i < 30 ; i++ )
	{
		if( suu[ i ] == 0 )
		{
			cout << i + 1 << endl ;
		}
	}
	return 0 ;
}