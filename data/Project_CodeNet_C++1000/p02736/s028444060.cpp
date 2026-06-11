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
int n, a[N], bk ,w1,w2; 
char s[N] ; 
signed main()
{
    n = gi(); scanf("%s", s ) ; n--;
    rep( i, 0, n ) {a[i] = s[i] - '1'; if (a[i]==1) bk = 1 ;} 
    rep( i, 0, n ) if( ( ( i  ) & ( n  ) ) == ( i  ) ) {if (a[i]==1) w1 ^= 1 ; if (a[i]==2) w2^=1;}
    if( w1 ) { printf("1") ; exit(0) ; }
    if( w2 && ( !bk ) ) { printf("2") ; exit(0) ; }
    printf("0") ; 
    return 0 ;
} 