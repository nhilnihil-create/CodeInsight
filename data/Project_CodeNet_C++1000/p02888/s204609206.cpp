#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N; cin>>N;
  vector<ll> vec(1001,0);
  vector<ll> list;
  rep(i,N)
  {
    ll l; cin>>l;
    vec.at(l)++;
  }
  list=vec;
  rep(i,1000)
  {
    vec.at(i+1)+=vec.at(i);
  }
  
  ll ans=0;
  //3辺異なる
  for(int i=1;i<=1000;i++)
  {
    for(int j=i+1;j<=1000;j++)
    {
      ans+=list.at(i)*list.at(j)*(vec.at(min(i+j-1,1000))-vec.at(j));
    }
  }
  //短長長
  for(int i=1;i<=1000;i++)
  {
    for(int j=i+1;j<=1000;j++)
    {
      if(list.at(j)>1)
      {
        ans+=list.at(i)*list.at(j)*(list.at(j)-1)/2;
      }
    }
  }
  //長短短
  for(int i=1;i<=1000;i++)
  {
    if(list.at(i)>1)
    {
      ll n=list.at(i);
      ans+=n*(n-1)/2*(vec.at(min(2*i-1,1000))-vec.at(i));
    }
  } 
  //正三角形
  for(int i=1;i<=1000;i++)
  {
    if(list.at(i)>2)
    {
      ll n=list.at(i);
      ans+=n*(n-1)*(n-2)/6;
    }
  }  
  cout<<ans<<endl;
  return 0;
}
