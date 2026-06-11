#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    
    vi p(a), q(b), r(c);
    rep(i,a)cin>>p[i];
    rep(i,b)cin>>q[i];
    rep(i,c)cin>>r[i];
    
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    
    rep(i,x)r.push_back(p[i]);
    rep(i,y)r.push_back(q[i]);
    
    sort(r.rbegin(), r.rend());
    
    ll ans = 0;
    
    rep(i,x+y)ans += r[i];
    
    cout << ans << endl;
    return 0;
}