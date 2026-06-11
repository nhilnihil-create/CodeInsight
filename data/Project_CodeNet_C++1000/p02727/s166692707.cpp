#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<int> p(a),q(b),r(c);
    rep(i,a) cin>>p[i];
    rep(i,b) cin>>q[i];
    rep(i,c) cin>>r[i];

    vector<int> pq;
    sort(all(p));
    reverse(all(p));
    rep(i,x) pq.push_back(p[i]);
    sort(all(q));
    reverse(all(q));
    rep(i,y) pq.push_back(q[i]);
    rep(i,c) pq.push_back(r[i]);

    sort(all(pq));
    reverse(all(pq));
    ll ans=0;
    rep(i,x+y) ans+=pq[i];

    cout<<ans<<endl;
}