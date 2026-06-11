
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;

int main(){
    FAST_IO ;
    bigint N ; cin >> N ;
    bigint ans = 0 ;
    map<bigint , bigint > m ;
    int arr[N] ;
    for( int i = 0 ; i < N ; i++ ){
        cin >> arr[i] ;
        m[arr[i]]++ ;
    }
    for( auto x : m ){
        if( x.second < 2 )
            continue ;
        ans += ( x.second * ( x.second - 1 ) ) / 2 ;
    }
    for( int i = 0 ; i < N ; i++ ){
        bigint sum = ans ;
        if( m[arr[i]] < 2 )
            cout << sum << endl ;
        else{
            bigint x = m[arr[i]] ;
            sum -= (x * ( x - 1 )) / 2 ;
            x -- ;
            if( x < 2 )
                cout << sum << endl ;
            else
                cout << sum + ( x * ( x - 1 )) / 2 << endl ;
        }
    }
    return 0 ;
}
