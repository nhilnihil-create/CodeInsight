#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)

int main(){
    int N,Q;
    cin>>N>>Q;
    dsu d(N);
    REP(i,Q){
        int t,u,v;
        cin>>t>>u>>v;
        if(!t){
            d.merge(u,v);
        }else{
            if(d.same(u,v)){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    }