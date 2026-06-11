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
  vector<string> vec(0);
  ll count=1;
  rep(i,N){
    string S; cin>>S;
    if(!mp.count(S)) mp[S]=1;
    else mp.at(S)++;
    
    if(count==mp.at(S)) vec.push_back(S);
    if(chmax(count,mp.at(S))) {vec=vector<string>(0); vec.push_back(S);}
  }
  
  sort(vec.begin(),vec.end());
  
  for(auto ans:vec) cout<<ans<<endl;
  return 0;
}