#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define p(t1,t2) pair<t1,t2>
using namespace std ;
int main(){
    ll N , K , i;
    cin >> N >> K ;
    v(int) P(N+1) , C(N+1) ;
    for(i=1;i<=N;++i) cin >> P[i] ;
    for(i=1;i<=N;++i) cin >> C[i] ;
    ll ans = INT64_MIN ;
    for(i=1;i<=N;++i){
        v(int) path ;
        int j = P[i] ;
        ll sum = 0 , cyclesum = 0 ;
        while(j!=i){
            sum += C[j] ;
            path.push_back(C[j]) ;
            j = P[j] ;
        }
        sum += C[i] ;
        path.push_back(C[i]) ;
        int m = path.size() ;
        for(j=0;j<m;++j){
            if(j<K){
                int lcnt = (K-1-j)/m ;
                cyclesum += path[j] ;
                ans=max(ans,cyclesum + max(sum*lcnt,sum*0)) ;
            }
        }
    }
    cout << ans << "\n" ;
    return 0 ;
}