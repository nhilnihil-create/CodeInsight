#include <iostream>
#include <map>

using namespace std;

int main( void )
{
	while (1)
	{
		map <char, char> T;

		int n;
		cin >> n;

		if ( n == 0)
			break;

		for ( int i = 0; i < n; ++i )
		{
			char c;
			cin >> c;
			cin >> T[c];
		}

		string answer;
		int m;
		cin >> m;
		for ( int i = 0; i < m; ++i )
		{
			char c;
			cin >> c;
			if( T.find(c) != T.end() )
				answer += T[c];
			else
				answer += c;
		}

		cout << answer << endl;
	}

	return 0;
}