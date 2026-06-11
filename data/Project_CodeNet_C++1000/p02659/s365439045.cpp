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
int power( int x, int n ){
    if( n == 0 ) return 1 ;
    else if( n & 1 ) return ( x * power( (x*x) % mod, n / 2 ) ) % mod ;
    return power( (x*x) % mod, n / 2 ) % mod ;
}
template<class T> void __print( v<T> &arr ){
    int n = arr.size() ;
    cerr << "[ " ;
    for( int i = 0 ; i < n ; i++ ) {
        cerr << arr[i] ;
        if( i != n - 1 ) cerr << ", " ;
    }
    cerr << " ]" << endl ;
}
template<class T> void __print( T arr[], int n ){ 
    cerr << "[ " ;
    for( int i = 0 ; i < n ; i++ ) {
        cerr << arr[i] ;
        if( i != n - 1 ) cerr << ", " ;
    }
    cerr << " ]" << endl ;
}
#define print(x) cerr << "{ " << #x << " : " << x << " } " ;
#define println(x) cerr << "{ " << #x << " : " << x << " }" << endl ;
// Template END
const int mx = (int)2e5 + 1 ;
class compare {
    // multiset<dataType, compare>
    // priority_queue<dataType, vector<dataType>, compare>
    public :
    // first - ratings, second - number
    bool operator()( const pair<int,int> &a, const pair<int,int> &b ){
        return a.first > b.first ;
    }
} ;

signed main(){
    int a ;
    float b ;
    cin >> a >> b ;
    int x = round(b * 100) ;
    cout << (int)(( a * x ) / 100) ;
    return 0 ;   
}          