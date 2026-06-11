#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int n, s;
	vector<int> flags;

	while ( cin >> n >> s )
	{
		if ( n == 0 && s == 0 )
		{
			break;
		}

		flags.clear();
		for ( int i = 0; i < 10; i++ )
		{
			flags.push_back( i < n ? 1 : 0 );
		}
		sort( flags.begin(), flags.end() );

		int count = 0;

		do
		{
			int sum = 0;

			for ( unsigned int i = 0; i < flags.size(); i++ )
			{
				if ( flags[i] )
				{
					sum += i;
				}
			}

			if ( s == sum )
			{
				count++;
			}
		} while ( next_permutation( flags.begin(), flags.end() ) );

		cout << count << endl;
	}
	
	return 0;
}