#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
#define PI 3.14159265358979323846264338327950288
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;

int pref[1000075] ;
int main(){
    FAST_IO ;
    string S , T ; cin >> S >> T ;
    int N = ( int ) S.size() ;
    int L = ( int ) T.size() ;
    int ans = L ;
    for( int i = 0 ; i < N - L + 1 ; i++ ){
        int d = 0 ;
        for( int j = 0 ; j < L ; j++ ){
            if( S[i+j] != T[j] )
                d++ ;
        }
        ans = min( d , ans ) ;
    }
    cout << ans << endl ;
    return 0 ;
    
}
 