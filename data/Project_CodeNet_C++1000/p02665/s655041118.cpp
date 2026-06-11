#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<ll,ll>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    vector<ll> p(n+1);
    rep(i,n+1) cin>>p[i];
    vector<P> q(n+1);
    q[n]={p[n],p[n]};
    rep(i,n){
        q[n-1-i].first=(q[n-i].first+1)/2+p[n-1-i];
        q[n-1-i].second=q[n-i].second+p[n-1-i];
    }
    if(q[0].first!=1){
        cout<<-1<<endl;
        return 0;
    }
    ll ans=1;
    ll che=1;
    rep(i,n){
        che=min(2*(che-p[i]),q[i+1].second);
        ans+=che;
    }
    cout<<ans<<endl;
    return 0;
}