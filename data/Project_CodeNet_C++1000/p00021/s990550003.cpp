#include <iostream>
using namespace std;
#define INF 10000000
int main( void )
{
	while ( !cin.eof() )
	{
		int n;
		cin >> n;

		if ( cin.eof() )
			break;

		for ( int i = 0; i < n; i++ )
		{
			double x1, x2, x3, x4;
			double y1, y2, y3, y4;

			cin >> x1 >> y1;
			cin >> x2 >> y2;
			cin >> x3 >> y3;
			cin >> x4 >> y4;

			double m1;
			double m2;
			if ( x2-x1 != 0 )
				m1 = (y2-y1)/(x2-x1);
			else
				m1 = INF;

			if ( x4-x3 != 0 )
				m2 = (y4-y3)/(x4-x3);
			else
				m2 = INF;

			if ( m1 == m2 )
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}

	}

	return 0;
}