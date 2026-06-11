#include<bits/stdc++.h>
#define del(a,i) memset(a,i,sizeof(a))
#define ll long long
#define inl inline
#define il inl void
#define it inl int
#define ill inl ll
#define re register
#define ri re int
#define rl re ll
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f
using namespace std ;
template< class T > inl T read() {
	T x = 0 ; int f = 1 ; char k = getchar() ;
	for( ; k > '9' || k < '0'; k = getchar() ) if( k == '-' ) f = -1 ;
	for( ; k >= '0' && k <= '9'; k = getchar() ) x = x * 10 + k - '0' ;
	return x * f ;
}
template< class T > inl T read( T &x ) { return x = read<T>() ; }
int _num, _buf[20];
template< class T > il print( T x ) {
   	if( x == 0 ) return putchar( '0' ) ,void() ;
	if( x < 0 ) putchar( '-' ), x = -x ;
	while( x ) _buf[++_num] = x % 10, x /= 10 ;
	while( _num ) putchar( _buf[_num--] + '0' ) ;
}
ll mul( ll a, ll b, ll mod ) { long double c = 1. ; return ( a * b - (ll)( c * a * b / mod ) * mod ) % mod ; }
it qpow( int x, int m, int mod ) {
	int res = 1, bas = x ;
	while(m) {
		if( m & 1 ) res = ( 1ll * res * bas ) % mod ;
		bas = ( 1ll * bas * bas ) % mod, m >>= 1 ;
	}
	return res ;
}
const int N = 2e5 + 5 ;
int n, val[N];
ll ans;
vector<int> G[N];
struct Seg_Tree {
	int tag;
	ll sum;
}T[N << 2];
#define lc ( cur << 1 )
#define rc ( cur << 1 | 1 )
il pushup( int cur ) {
	T[cur].sum = T[lc].sum + T[rc].sum ;
}
il maintain( int cur, int l, int r, int k ) {
	T[cur].tag += k ;
	T[cur].sum += 1ll * k * ( r - l + 1 ) ;
}
il pushdown( int cur, int l, int r ) {
	if( !T[cur].tag )
		return ;
	maintain( lc, l, mid, T[cur].tag ) ;
	maintain( rc, mid + 1, r, T[cur].tag ) ;
	T[cur].tag = 0 ;
}
il Build( int cur, int l, int r ) {
	if( l == r ) {
		T[cur].sum = val[l] ;
		return ;
	}
	Build( lc, l, mid ), Build( rc, mid + 1, r ) ;
	pushup( cur ) ;
}
il Updata( int cur, int l, int r, int L, int R, int k ) {
	if( l >= L && r <= R ) {
		maintain( cur, l, r, k ) ;
		return ;
	}
	pushdown( cur, l, r ) ;
	if( mid >= L )
		Updata( lc, l, mid, L, R, k ) ;
	if( R > mid )
		Updata( rc, mid + 1, r, L, R, k ) ;
	pushup( cur ) ;
}
int main() {
//	freopen( ".in", "r", stdin ) ;
//	freopen( ".out", "w", stdout ) ;
	n = read<int>() ;
	for( ri i = 1; i <= n; ++i )
		val[i] = 1 ;
	for( ri i = 1; i < n; ++i ) {
		int u = read<int>(), v = read<int>() ;
		if( u > v )
			swap( u, v ) ;
		G[u].push_back( v ) ;
		val[v] -= 1 ;
	}
	for( ri i = 1; i <= n; ++i )
		val[i] += val[i - 1] ;
	Build( 1, 1, n ) ;
	ans += T[1].sum ;
	for( ri i = 1; i < n; ++i ) {
		Updata( 1, 1, n, i, n, -1 ) ;
		for( auto x: G[i] )
			Updata( 1, 1, n, x, n, 1 ) ;
		ans += T[1].sum ;
	}
	print( ans ), puts( "" ) ;
	cerr << 1. * clock() / CLOCKS_PER_SEC << "\n" ;
	return 0;
}