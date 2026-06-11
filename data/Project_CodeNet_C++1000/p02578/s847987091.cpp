#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 100000
#define endl "\n"
#define PI 3.14159265358979323846264338327950288
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;


int main(){
    FAST_IO ;
    int N ; cin >> N ;
    int arr[N+1] ;
    for( int i = 0 ; i < N ; i++ ){
        cin >> arr[i] ;
    }
    bigint ans = 0 ;
    
    for( int i = 1 ; i < N ; i++ ){
        if( arr[i] < arr[i-1] ){
            ans = ans + max( 0 , arr[i-1] - arr[i]) ;
            arr[i] = arr[i-1] ;
        }
    }
    cout << ans << endl ;
    return 0 ;
}
 