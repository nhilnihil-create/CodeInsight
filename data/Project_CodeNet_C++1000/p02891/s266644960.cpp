#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1);





int main() 
{
  string S; cin>>S;
  ll K; cin>>K;
  vector<ll> vec(1,1);
  rep(i,S.size()-1)
  {
    if(S.at(i)==S.at(i+1)) {vec.at(vec.size()-1)++; continue;}
    vec.push_back(1);
  }
  if(vec.size()==1)
  {
    cout<<S.size()*K/2<<endl;
    return 0;
  }  
  ll ans=0;
  if(S.at(0)!=S.at(S.size()-1))
  {
    ans+=vec.at(0)/2*K+vec.at(vec.size()-1)/2*K;
  }
  else
  {
    ans+=vec.at(0)/2+vec.at(vec.size()-1)/2+(vec.at(0)+vec.at(vec.size()-1))/2*(K-1);
  }
  for(int i=1;i<vec.size()-1;i++)
  {
    ans+=vec.at(i)/2*K;
  }
  cout<<ans<<endl;
  return 0;
}