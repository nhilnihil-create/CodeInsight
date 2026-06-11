#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( v, c ) for ( auto &v : c )

#define EACH( it, c ) for ( auto it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()
#define DRANGE( c, p ) (c).begin(), (c).begin() + p, (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	while ( true )
	{
		int a, l;
		cin >> a >> l;

		if ( !( a | l ) )
		{
			break;
		}

		map<int,int> done;
		done[ a ] = 0;

		int res = 0, res2;
		while ( true )
		{
			res++;

			OSS oss;
			oss << setw( l ) << setfill( '0' ) << a;
			string mins( oss.str() ), maxs( oss.str() );
			sort( ALL( mins ) );
			sort( ALL( maxs ), greater<char>() );
			int ma, mi;
			{
				ISS iss( mins );
				iss >> mi;
				ISS iss2( maxs );
				iss2 >> ma;
			}
			if ( EXIST( done, ma - mi ) )
			{
				res2 = ma - mi;
				break;
			}
			a = ma - mi;
			done[ ma - mi ] = res;
		}

		cout << done[ res2 ] << ' ' << res2 << ' ' << res - done[ res2 ] << endl;
	}

	return 0;
}