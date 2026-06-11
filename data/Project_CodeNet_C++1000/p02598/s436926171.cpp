#include <bits/stdc++.h>
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
    int n,k; cin>>n>>k;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    int r=0, l=1e9+5;
    while(l-r>1){
        int m=(r+l)/2;
        int kari=0;
        rep(i,n){
            kari+=(p[i]+m-1)/m-1;
        }
        if(kari<=k){
            l=m;
        }else{
            r=m;
        }
    }
    cout<<l<<endl;
    return 0;
}