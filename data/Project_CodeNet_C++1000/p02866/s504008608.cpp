#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int  i = 0 ; i < n ; i++ ) 
typedef long long ll ;

int main(){
    int n ;
    cin >> n ;
    vector<int> A(n) ;
    rep(i,n) cin >> A.at(i) ;
    for(int i = 1 ; i < n ; i++ ){
        if( A.at(i)== 0 ){
            cout << 0 << endl;
            return 0 ;
        }
    }
    int maxA = 0 ;
    ll ans = 1 ;
    rep(i,n) maxA = max(maxA,A.at(i)) ;
    vector<int> B(maxA+1) ;
    rep(i,n) B.at( A.at(i) )++ ;
    rep(i,maxA+1){
        if( B.at(i) == 0 ){
        cout << 0 << endl;
        return 0 ;
        } 
    }
    for(int i = 0 ; i < maxA ; i++ ){
        rep(j,B.at(i+1)){
            ans *= B.at(i) ;
            ans %= 998244353 ;
        }
    }
    cout  << ans%998244353  <<endl;
}
