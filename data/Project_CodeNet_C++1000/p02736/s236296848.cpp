#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
int n, a[N], w[10], bk[10] ; 
char s[N] ; 
signed main()
{
	n = gi(), scanf("%s", s + 1 ) ;
	rep( i, 1, n ) a[i] = s[i] - '1', bk[a[i]] = 1 ; 
	rep( i, 1, n ) if( ( ( i - 1 ) & ( n - 1 ) ) == ( i - 1 ) ) w[a[i]] ^= 1 ; 
	if( w[1] ) { puts("1") ; exit(0) ; }
	if( w[2] && ( !bk[1] ) ) { puts("2") ; exit(0) ; }
	puts("0") ; 
	return 0 ;
} 