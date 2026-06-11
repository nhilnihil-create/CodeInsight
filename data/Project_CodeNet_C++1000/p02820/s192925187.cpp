#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,K; cin>>N>>K;
  ll R,S,P; cin>>R>>S>>P;
  string T; cin>>T;
  vector<string> vec(K,"");
  rep(i,N)
  {
    vec.at(i%K).push_back(T.at(i));
  }
  ll ans=0;
  for(auto str:vec)
  {
    rep(i,str.size())
    {
      if(str.at(i)=='s') {ans+=R;}
      if(str.at(i)=='p') {ans+=S;}
      if(str.at(i)=='r') {ans+=P;}
      if(i==str.size()-1) {break;}
      if(str.at(i)==str.at(i+1)) {i++;}
    } 
  }
  cout<<ans<<endl;
  return 0;
}
