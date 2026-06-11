#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  string s,t;
  cin >> s >> t;
  ll n = s.size();
  vector<vector<int>> v(26);
  rep(i,n)v[s[i]-'a'].push_back(i);
  ll cnt = 0,pos = 0;
  rep(i,t.size()){
    auto iter = lower_bound(ALL(v[t[i]-'a']),pos);
    if(iter == v[t[i]-'a'].end()){
      cnt++;
      pos = 0;
      auto iter_ = lower_bound(ALL(v[t[i]-'a']),pos);
      if(iter_ == v[t[i]-'a'].end()){
        cout  << -1 << endl;
        return 0;
      }
      pos = *iter_+1;
      continue;
    }
    pos = *iter+1;
  }
  cout << cnt*n+pos << endl;





  return 0;
}