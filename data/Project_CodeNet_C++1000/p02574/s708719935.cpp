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

int cnt[2000005] ;
int gcd( int a , int b ){
    if( b == 0 )
        return a ;
    return gcd( b , a % b ) ;
}
int main(){
    FAST_IO ;
    int N ; cin >> N ;
    int G = 0 ;
    bool flag = false ;
    for( int i = 0 ; i < N ; i++ ){
        int x ; cin >> x ;
        G = gcd( G , x ) ;
        cnt[x]++ ;
    }
    if( G != 1 ){
        cout << "not coprime" << endl ;
        return 0 ;
    }
    int ans = 0 ;
   
    for( int i = 2 ; i <= 1000000 ; i++ ){
            ans = 0 ;
            for( int j = i ; j <= 1000000 ; j += i ){
                if( cnt[j] > 0 ){
                    ans += cnt[j] ;
                }
            }
        if( ans > 1 ){
            flag = true ;
            break ;
        }
    }
    if( flag && G == 1 ){
        cout << "setwise coprime" << endl ;
    }
    else
        cout << "pairwise coprime" << endl ;
    return 0 ;
}
 
 