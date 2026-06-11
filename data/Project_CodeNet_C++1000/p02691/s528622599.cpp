#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    map<int,int> pp, pm;
    rep(i,n){
        pp[p[i]+i+1]++;
        pm[i+1-p[i]]++;
    }
    ll ans=0;
    for(auto &v: pp){
        if(pm[v.first]!=0){
            ans+=ll(v.second)*ll(pm[v.first]);
        }
    }
    cout<<ans<<endl;
    return 0;
}