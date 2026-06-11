#include <iostream>
using namespace std;

int bit_count( const int n )
{
	int cnt = 0;
	for ( int i = 0; i < 10; i++ )
	{
		if ( n & 1 << i ) cnt++;
	}
	return cnt;
}

int main( void )
{
	int n, s;
	while ( cin >> n >> s )
	{
		if ( n == 0 && s == 0 ) break;
		int answer = 0;
		for ( int i = 0; i < 1 << 10; i++ )
		{
			if ( bit_count( i ) == n )
			{
				int sum = 0;
				for ( int j = 0; j < 10; j++ )
				{
					if ( i & 1 << j )
					{
						sum += j;
					}
				}
				if ( sum == s )
				{
					answer++;
				}
			}
		}
		cout << answer << endl;
	}

	return 0;
}