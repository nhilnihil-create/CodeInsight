#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007

int n , m , cnt , lim ;
int a[ MAXN ] ;

int b[ MAXN ] ;
int lft[ MAXN ] ;
int add[ MAXN ] ;

bool f ( int id ) {
    int val = a[ id ] + m ;
    long long sm = 0 ;
    long long lg = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( i == id ) { continue ; }
        int aux = val - a[ i ] ;
        if ( aux < 0 ) { ++ lg ; continue ; }
        sm += min ( aux , m ) ;
    }
    sm = 1LL * m * ( cnt - 1 ) - sm ;
    long long sr = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == id ) { continue ; }
        if ( sm <= 0 ) {
            if ( a[ i ] > val ) { ++ sr ; }
            continue ;
        }
        int aux = 0 ;
        if ( a[ i ] > val ) { aux = m ; }
        else {
            aux = m - min ( val - a[ i ] , m ) ;
        }
        sm -= aux ;
        if ( aux > 0 ) { ++ sr ; }
    }
    return ( sr + 1 <= lim ) ;
}

void input ( ) {
    scanf ( "%d%d%d%d" , &n , &m , &cnt , &lim ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 , greater < int > ( ) ) ;
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == false ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( r ) == false ) { -- r ; }
    printf ( "%d\n" , r ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
