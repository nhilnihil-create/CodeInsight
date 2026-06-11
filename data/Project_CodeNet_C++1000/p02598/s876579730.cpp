#include<bits/stdc++.h>
using namespace std ;

/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long int
#define all(y) y.begin(), y.end()
#define present( x, y ) (x.find( y ) != x.end())
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
const int mod = (int)1e9 + 7 ;
/************************************************************/
int cuts( int &x, int &s ){
    if( x % s == 0 ){
        return ( x / s - 1 ) ;
    }
    else return ( x / s ) ;
}

bool check( vector<int> &a, int &mid, int &k ){
    int len = a.size() ;
    int res = 0 ;
    for( int i = 0 ; i < len ; i++ ){
        res += cuts( a[i], mid ) ;
    }
    if( res > k ) return false ; // go below 
    else return true ;  // go ahead  
}

signed main(){
    int N, K ; cin >> N >> K ;
    vector<int> A(N) ;
    for( int i = 0 ; i < N ; i++ ) cin >> A[i] ;
    int low = 1, high = (int)2e9 ;
    int mid ;
    while( high - low + 1 >= 2 ) {
        mid = low + ( high - low ) / 2 ;
        // cout << mid << endl ;
        if( check(A, mid, K) ){
            high = mid ;
        }
        else{
            low = mid + 1 ;
        }
    }
    cout << low ;
    return 0 ;   
}