#include<bits/stdc++.h>
#define rep(i,n) for(i=0; i<n; ++i)
#define lim 100000
typedef long long ll;
using namespace std;
int main(void){
  int i,x,y,a,b,c; cin>>x>>y>>a>>b>>c;
  vector<ll> p(lim,0),q(lim,0),r(lim,0);
  rep(i,a) cin>>p[i]; sort(p.rbegin(),p.rend()); p[x]=0;
  rep(i,b) cin>>q[i]; sort(q.rbegin(),q.rend()); q[y]=0;
  rep(i,c) cin>>r[i]; sort(r.rbegin(),r.rend());
  int s=0,t=0,u=0,m;
  ll c1=0,c2=0,c3=0;
  rep(i,a+b+c){
    m=max(p[s],max(q[t],r[u]));
    if(p[s]==m&&s<x) c1+=p[s++];
    else if(q[t]==m&&t<y) c2+=q[t++];
    else c3+=r[u++];
    if(s+t+u==x+y) break;
  }
  cout<<c1+c2+c3;
  return 0;
}