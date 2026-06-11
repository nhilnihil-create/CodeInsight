#include<iostream>

using namespace std ;

int main()
{
	int h ,w ;
	while( cin >> h >> w ,h | w )
	{
			for( int i = w ; i > 0 ; i-- ,cout << "#" ) ;
		for( ; h > 2 ; h-- )
		{
			cout << endl << "#" ;
			for( int i = w - 1 ; i > 1 ; i-- ,cout << "." ) ;
			cout << "#" ;
		}
		cout << endl ;
		for( ; w > 0 ; w-- ,cout << "#" ) ;
		cout << endl << endl ;
	}
	return 0 ;
}