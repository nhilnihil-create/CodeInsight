#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  int n;
  ll d,a;
  cin>>n>>d>>a;
  vector<pair<ll,ll>> v(n);
  vector<ll> pos(n),bomb(n+1,0);
  for(int i=0;i<n;++i)
  {
    ll x,h;
    cin>>x>>h;
    v[i]={x,h};
    pos[i]=x;
  }
  sort(v.begin(),v.end());
  sort(pos.begin(),pos.end());
  ll b=(v[0].second%a)==0?(v[0].second/a):(v[0].second/a)+1;
  int idx=upper_bound(pos.begin(),pos.end(),pos[0]+2*d)-pos.begin();
  bomb[0]=b;
  bomb[idx]=-b;
  ll curbomb=a*b;
  for(int i=1;i<n;++i)
  {
    ll inx=pos[i],health=v[i].second;
    if(health>curbomb && bomb[i]==0)
    {
      idx=upper_bound(pos.begin(),pos.end(),inx+2*d)-pos.begin();
      b=((health-curbomb)%a)==0?((health-curbomb)/a):((health-curbomb)/a)+1;
      curbomb+=(a*b);
      bomb[i]+=b;
      bomb[idx]-=b;
    }
    else if(bomb[i]<0)
    {
      ll heal=a*llabs(bomb[i]);
      curbomb-=heal;
      bomb[i]=0;
      if(health>curbomb)
      {
        idx=upper_bound(pos.begin(),pos.end(),inx+2*d)-pos.begin();
        b=((health-curbomb)%a)==0?((health-curbomb)/a):((health-curbomb)/a)+1;
        curbomb+=(a*b);
        bomb[i]+=b;
        bomb[idx]-=b;
      }
    }
  }
  for(int i=1;i<n;++i)
    bomb[i]+=bomb[i-1];
  //for(auto i:bomb)
    //cout<<i<<" ";
    //cout<<endl;
  cout<<*max_element(bomb.begin(),bomb.end())<<endl;
  return 0;
}