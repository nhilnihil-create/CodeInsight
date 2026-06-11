#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"

using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;

int main(){
    bigint p2[100001] = { 0 }, p3[100001] = { 0 } ;
    p2[0] = 1 , p3[0] = 1 ;
    for( int i = 1 ; i < 100001 ; i++ )
        p2[i] = ( p2[i-1] * 2 ) % mod ;
    for( int i = 1 ; i < 100001 ; i++ )
        p3[i] = ( p3[i-1] * 3 ) % mod ;
    string str ; cin >> str ;
    int N = ( int ) str.length() ;
    int cnt = 0 ;
    bigint ans = 0 ;
    for( int i = 0 ; i < N ; i++ ){
        if( str[i] == '1' ){
            (ans += ( p2[cnt] * p3[N-i-1] ) % mod ) %= mod ;
            cnt++ ;
        }
    }
    (ans += p2[cnt]) %= mod ;
    cout << ans << endl ;
    return 0 ;
}
