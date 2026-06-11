#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<ll>p(a),q(b);
    vector<ll>r(x+y+c);
    rep(0,i,a)cin>>p[i];
    rep(0,i,b)cin>>q[i];
    sort(p.rbegin(),p.rend());
    sort(q.rbegin(),q.rend());
    rep(0,i,x)r[i]=p[i];
    rep(0,i,y)r[x+i]=q[i];
    rep(0,i,c)cin>>r[x+y+i];
    sort(r.rbegin(),r.rend());
    ll ans=0;
    rep(0,i,x+y){
        ans+=r[i];
        //cout<<r[i]<<endl;
    }
    cout<<ans;
}