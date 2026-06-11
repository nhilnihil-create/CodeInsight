#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N; cin>>N;
  map<string,ll> mp;
  rep(i,N){
    string S; cin>>S;
    if(!mp.count(S)) mp[S]=1;
    else mp.at(S)++;
  }
  
  vector<string> vec(0);
  ll count=-INF;
  for(auto p:mp){
    string key; ll value; tie(key,value)=p;
    chmax(count,value);
  }
  for(auto p:mp){
    string key; ll value; tie(key,value)=p;
    if(count==value) vec.push_back(key);
  }
  
  for(auto ans:vec) cout<<ans<<endl;
  return 0;
}