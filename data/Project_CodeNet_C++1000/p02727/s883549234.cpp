#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
  vector<ll> p(a);
  vector<ll> q(b);
  vector<ll> r(c);
  int i;
  rep(i,a)cin>>p[i];
  rep(i,b)cin>>q[i];
  rep(i,c)cin>>r[i];
  sort(all(p));
  reverse(all(p));
  sort(all(q));
  reverse(all(q));
  sort(all(r));
  reverse(all(r));
  priority_queue<ll,vector<ll>,greater<ll>> pq;
  rep(i,x)pq.push(p[i]);
  rep(i,y)pq.push(q[i]);
  int ind=0;
  while(ind<c)
  {
    ll s=pq.top();
    if(s<r[ind])
    {
      pq.pop();
      pq.push(r[ind]);
      ind++;
    }
    else break;
  }
  ll ans=0;
  while(!pq.empty())
  {
    ll now=pq.top();
    pq.pop();
    ans+=now;
  }
  cout<<ans<<endl;
}
