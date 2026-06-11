#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

template<typename T> bool chmax( T &a, const T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using ll = long long;
using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair

#define F first
#define S second

#define popcnt __builtin_popcountll

#define rep( i, n ) for ( ll i = 0; i < (ll)( n ); ++i )
#define reps( i, n ) for ( ll i = 1; i <= (ll)( n ); ++i )
#define rrep( i, n ) for ( ll i = (ll)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( ll i = (ll)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();
template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }


int main()
{
	ll n; cin >> n;
	vector<ll> a( n );
	rep( i, n ) cin >> a[i];
	map<ll, ll> c, d;
	rep( i, n ) c[a[i]]++;
	reps( i, n ) d[c[i]]++;
	vector<ll> sumkd( n + 2 ), sumxd( n + 2 );
	rep( i, n + 1 )
	{
		sumkd[i + 1] = sumkd[i] + i * d[i];
		sumxd[i + 1] = sumxd[i] + d[i];
	}

	vector<ll> f( n + 1 );
	reps( x, n )
		f[x] = ( ( sumkd[x] - sumkd[0] ) + x * ( sumxd[n] - sumxd[x] ) ) / x;
	sort( ALL( f ) );

	reps( k, n )
	{
		if ( k == 1 ) cout << n << endl;
		else
		{
			auto it = lower_bound( ALL( f ), k );
			cout << n - ( it - f.begin() ) + 1 << endl;
		}
	}

	return ( 0 );
}
