#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll  n ;
    cin >> n ;
    vector<ll> A(100005,0) ;
    A[100] = 1 ;
    A[101] = 1 ;
    A[102] = 1 ;
    A[103] = 1 ;
    A[104] = 1 ;
    A[105] = 1 ;
    for(int i =  105 ; i <= 100005 ; i++ ){
      if( A[i-100] == 1 ) A[i] = 1 ;
      if( A[i-101] == 1 ) A[i] = 1 ;
      if( A[i-102] == 1 ) A[i] = 1 ;
      if( A[i-103] == 1 ) A[i] = 1 ;
      if( A[i-104] == 1 ) A[i] = 1 ;
      if( A[i-105] == 1 ) A[i] = 1 ;
    }
    cout << A[n] << endl ; 
}