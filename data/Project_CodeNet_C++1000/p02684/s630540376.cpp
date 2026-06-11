#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>>next(60,vector<ll>(n));
    rep(0,i,n){
        cin>>next[0][i];
        --next[0][i];
    }
    rep(0,d,60-1){
        rep(0,i,n){
            next[d+1][i]=next[d][next[d][i]];
        }
    }
    ll v=0;
    rep(0,d,60){
        if(k&(1LL<<d))v=next[d][v];
    }
    cout<<v+1<<endl;
}