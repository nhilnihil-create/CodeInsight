#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<vector<int>> next(60,vector<int>(n));
    rep(v, n) cin>>next[0][v], next[0][v]--;
    for(int d=0;d+1<60;d++){
        rep(v,n){
            next[d+1][v]=next[d][next[d][v]];
        }
    }
    int v=0;
    rep(d,60){
        if(k&(1LL<<d)) v=next[d][v];
    }
    cout<<v+1<<endl;
}