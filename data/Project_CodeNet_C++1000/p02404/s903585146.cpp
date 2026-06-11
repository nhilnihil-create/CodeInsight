 #include <iostream>
using namespace std;

int main()
{
	int w , h , x , y , n , i ;
	while ( 1 )
	{
		y = 1 ;
		cin >> h >> w ;
		 3 <= h , w <= 100 ;
		if ( h == 0 && w == 0 ) break ;
		for( i = 1 ; i <= w ; i ++ )
			cout << "#" ;
	cout << endl; 
	while( y < h - 1 )
	{
		cout << "#" ;
		for ( n = 1 ; n <= w - 2 ; n ++ )
			cout << "." ;
		y ++ ;
		cout << "#" << endl;
	}
		for ( x = 1 ; x <= w ; x ++ )
			cout << "#" ;
		cout << endl;
		cout << endl;
}
}