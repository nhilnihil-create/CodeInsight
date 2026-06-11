#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll n , k ;
    cin >> n >> k ;
    vector<ll> A(n) ;
    rep(i,n) cin >> A.at(i) ;
    rep(i,n) A.at(i)-- ;
    map<ll,ll> where ;
    ll now = 0 ;//今いる場所
    ll count=0 ;//カウント
    ll two = 0 ;//二週目に入ったときの回数
    ll three=0 ;//三週目に入ったときの回数
    where[now] = 1 ;
    bool flag =true ;
    while(1){
        if( count == k ){
            cout << now + 1 << endl ;
            return 0 ;
        }//移動回数が十分小さい場合には，この段階で出力する．
        now = A[now] ;
        where[now]++ ;
        count++ ;
        if(where[now] == 2 & flag ){
            two = count ;
            flag = false ;
        } 
        if(where[now]==3){ 
            three = count ;
            break ;
        }
    }
    ll amari = ( k - two )%( three - two ) ;
    //周期移動の開始時点から周期移動を考慮すること
    rep(i,amari){
        now = A[now] ;
    }
    cout << now + 1 << endl ;
}
