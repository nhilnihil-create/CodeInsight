#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vll=vector<ll>;
int main(){
  ll x,y,a,b,c,ans=0;
  cin>>x>>y>>a>>b>>c;
  vll p,q,r,np,nq;
  for(ll i=0;i<a;i++){
    ll ai;
    cin>>ai;
    p.push_back(ai);
  }for(ll i=0;i<b;i++){
    ll bi;
    cin>>bi;
    q.push_back(bi);
  }for(ll i=0;i<c;i++){
    ll ci;
    cin>>ci;
    r.push_back(ci);
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  sort(q.begin(),q.end());
  reverse(q.begin(),q.end());
  for(ll i=0;i<x;i++){
    np.push_back(p.at(i));
  }for(ll i=0;i<y;i++){
    nq.push_back(q.at(i));
  }
  np.insert(np.end(),nq.begin(),nq.end());
  np.insert(np.end(),r.begin(),r.end());
  sort(np.begin(),np.end());
  reverse(np.begin(),np.end());
  for(ll i=0;i<x+y;i++){
    ans+=np.at(i);
  }
  cout<<ans<<endl;
}