#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<ll> p(a),q(b),r(c);
    rep(i,a) cin>>p[i];
    rep(i,b) cin>>q[i];
    rep(i,c) cin>>r[i];
    sort(all(p));
    reverse(all(p));
    sort(all(q));
    reverse(all(q));
    vector<ll> v;
    rep(i,x) v.push_back(p[i]);
    rep(i,y) v.push_back(q[i]);
    rep(i,c) v.push_back(r[i]);
    sort(all(v));
    reverse(all(v));
    ll ans=0;
    rep(i,x+y) ans+=v[i];

    cout<<ans<<endl;

} 
