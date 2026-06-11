#include<iostream>

using namespace std ;

int main()
{
	int h ,w ;
	char str[ 2 ][ 3 ] = { { "#." } ,{ ".#" } , } ;
	while( cin >> h >> w ,h | w )
	{
		for( int i = 0 ; i < h ; i++ )
		{
			for( int j = 0 ; j < w ; j++ )
				cout << str[ i % 2 ][ j % 2 ] ;
			cout << endl ;
		}
		cout << endl ;
	}
	return 0 ;
}