#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
int main(){long long x,y,a,b,c,d=0; cin>>x>>y>>a>>b>>c; vector<int> p(a),q(b),r(c); rep(i,a) cin>>p[i]; rep(i,b) cin>>q[i]; rep(i,c) cin>>r[i]; sort(p.rbegin(),p.rend()); sort(q.rbegin(),q.rend()); rep(i,x) r.push_back(p[i]); rep(i,y) r.push_back(q[i]); sort(r.rbegin(),r.rend()); rep(i,x+y) d+=r[i]; cout<<d;}