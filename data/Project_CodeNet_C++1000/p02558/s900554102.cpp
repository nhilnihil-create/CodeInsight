#include <atcoder/all>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n,q; cin>>n>>q;
    dsu unionfind(n);
    rep(i,q){
        int t,u,v; cin>>t>>u>>v;
        if(t==0){
            unionfind.merge(u,v);
        }else if(t==1){
            cout << unionfind.same(u,v) << endl;
        }
    }

    return 0;
}