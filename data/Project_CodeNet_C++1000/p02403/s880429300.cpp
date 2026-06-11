#include<iostream>

using namespace std ;

int main()
{
	int h ,w ;
	while( cin >> h >> w ,h )
	{
		for( ; h > 0 ; h-- )
		{
			for( int i = w ; i > 0 ; i-- )
				cout << "#" ;
			cout << endl ;
		}
		cout << endl ;
	}
	return 0 ;
}