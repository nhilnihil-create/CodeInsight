#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll n , k ;
    cin >> n >> k ;
    vector<ll> P(n) ;
    vector<ll> C(n) ;
    rep(i,n){
        cin >> P.at(i) ;
        P.at(i)-- ;
    }
    rep(i,n){
        cin >> C.at(i) ;
    }
    ll ans = -1e18 ;
    rep(start,n){
        ll tot = 0 ;
        vector<ll> S ;
        ll now = start ;
        //周期を求める．
        while (1){
            now = P[now] ;//場所の更新
            S.push_back(C[now]) ;//移動先の配列をとる．
            tot += C[now] ;//一周した後の合計が正か負かで場合分け
            if(now == start) break ;//一周したらbreak 
        }
        ll l = S.size() ;
        ll tem = 0 ;
        ll t = 0 ;
        rep(i,l){
            t += S[i] ;
            if( i+1 > k ) break ;
            ll now = t ;
            if( tot > 0 ){
                ll e = ( k - i - 1 )/ l ;
                now += tot*e ;
            }
            ans = max(ans,now) ;
        }
    } 
    cout << ans <<endl ; 
}