#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)




int main(){
    int n,q; cin>>n>>q;
    atcoder::dsu uf(n);
    rep(i,q){
        int a,b,c; cin>>a>>b>>c;
        if(a==0){
            uf.merge(b,c);
        }else{
            if(uf.same(b,c)){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
}