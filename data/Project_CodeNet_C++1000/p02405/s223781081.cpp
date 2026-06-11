 #include <iostream>
using namespace std;

int main()
{
	int h , w , x , y , n ;
	n = 1 ;
	while( 1 )
	{
		if ( n >= 2 )
			cout << endl;
		y = 1 ;
		cin >> h >> w ;
		if ( h == 0 && w == 0 ) break ;
        h , w <= 300 ;
        while ( y <= h )
        {
        	if ( y >= 2 )
        		cout << endl;
        	if ( y % 2 != 0 )
        	{
        		for ( x = 5 ; x < w + 5 ; x ++ )
        		{
        			if ( x % 2 == 0 )
        			{
        				cout << "." ;
        			}
        			if ( x % 2 != 0 )
        			{
        				cout << "#" ;
        			}
        		}
        	}
        	if ( y % 2 == 0 )
        	{
        for ( x = 5 ; x < w + 5 ; x ++ )
        {
        	if ( x % 2 == 0 )
        	{
        		cout << "#" ;
        	}
        	if ( x % 2 != 0 )
        	{
        		cout << "." ;
        	}
        }
        }
        y ++ ;
        n ++ ;
        }  
        cout << endl;
	}
}