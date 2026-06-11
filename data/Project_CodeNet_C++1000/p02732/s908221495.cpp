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
  map<ll,ll> list;
  vector<ll> A(N);
  rep(i,N)
  {
    cin>>A.at(i);
    if(list.count(A.at(i))) {list.at(A.at(i))++; continue;}
    list[A.at(i)]=1;
  }
  ll ans=0;
  for(auto p:list)
  {
    ll hoge=p.second;
    ans+=hoge*(hoge-1)/2;
  }
  rep(k,N)
  {
    ll a=A.at(k);
    ll count=list.at(a);
    cout<<ans-(count-1)<<endl;
  }  
  return 0;
}
