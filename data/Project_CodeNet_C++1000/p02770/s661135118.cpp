#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5000 + 5 ;
int n, q, d[N], sum[N], pre[N], c[N] ; 
signed main()
{
	n = gi(), q = gi() ;
	rep( i, 1, n ) d[i - 1] = gi() ; 
	while( q-- ) {
		int l = gi(), x = gi(), M = gi() ;
		int Ans = 0, sum = 0, ans = 0 ; x %= M ;
		for( re int i = 0; i < n; ++ i ) {
			c[i] = d[i] % M, sum += c[i] ; 
			if( c[i] != 0 ) ++ ans ;
		}
		int mt = ( l - 1 ) / n ;
		int sumx = ( x + mt * sum ) ;
		Ans = ans * mt - ( sumx / M ) ;
		sumx %= M ; 
		for( re int i = 0; i < ( l - 1 ) % n; ++ i ) {
			sumx += c[i] ; 
			if( c[i] != 0 ) ++ Ans ; 
			if( sumx >= M ) sumx -= M, -- Ans ;
		}
		cout << Ans << endl ;
	}
	return 0 ;
}