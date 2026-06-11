#include<bits/stdc++.h>
using namespace std ;

// Template START
#define endl "\n"
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define all(y) y.begin(), y.end()
#define present( x, y ) (x.find( y ) != x.end())
const int mod = (int)1e9 + 7 ;
template<class T>
auto matrix( int r, int c, T v ){
    return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
template<class T>
auto matrix( int o1, int o2, int o3, T v ){ 
    return vector<vector<vector<T>>>( o1, vector<vector<T>>( o2, vector<T>( o3, v ) ) ) ;
}
#define v vector
// Template END

int power( int x, int n ){
    if( n == 0 ) return 1 ;
    else if( n & 1 ) return ( x * power( (x*x) % mod, n / 2 ) ) % mod ;
    return power( (x*x) % mod, n / 2 ) % mod ;
}

signed main(){
    int n ; cin >> n ;
    v<pair<int,int>> coords(n) ;
    for( int i = 0 ; i < n ; i++ ) cin >> coords[i].first >> coords[i].second ;
    int pMax = coords[0].first + coords[0].second ;
    int pMin = pMax ;
    int mMax = coords[0].first - coords[0].second ;
    int mMin = mMax ;
    for( int i = 1 ; i < n ; i++ ){
        int temp1 = coords[i].first + coords[i].second ;
        int temp2 = coords[i].first - coords[i].second ;
        pMax = max( pMax, temp1 ) ;
        pMin = min( pMin, temp1 ) ;
        mMax = max( mMax, temp2 ) ;
        mMin = min( mMin, temp2 ) ;
    }
    cout << max( abs(pMax - pMin), abs(mMax - mMin) ) ;
    return 0 ;   
}          