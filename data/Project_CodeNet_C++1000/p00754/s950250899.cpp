#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = INT_MAX / 4;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); i++ )
#define UREP( i, m, n ) for ( ui i = (ui)( m ); i < (ui)( n ); i++ )
#define EACH( v, c ) for ( __typeof( c.front() ) &v : c )

#define ITER( c ) __typeof( (c).begin() )
#define IREP( c, it ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()
#define RALL( c ) (c).rbegin(), (c).rend()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

int main()
{
	while ( true )
	{
		string line;
		getline( cin, line );

		if ( line == "." )
		{
			return 0;
		}

		bool yes = true;
		char c;
		stack<char> st;
		istringstream iss( line );

		while ( iss >> c )
		{
			if ( c == '(' || c == '[' )
			{
				st.push( c );
			}
			else if ( c == ')' || c == ']' )
			{
				int c2 = ( c == ')' ? '(' : '[' );

				if ( !st.empty() && st.top() == c2 )
				{
					st.pop();
				}
				else
				{
					yes = false;
				}
			}
		}

		if ( yes && st.empty() )
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}				

	return 0;
}