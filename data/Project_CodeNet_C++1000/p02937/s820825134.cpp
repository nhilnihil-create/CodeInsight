#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s,t;
  cin>>s>>t;
  ll sl=s.size(),tl=t.size();
  vector<vector<ll>> v(26);
  for(ll i = 0LL; i < sl;i++){
    v[s[i]-'a'].push_back(i);
  }
  ll cnt = 0LL;
  ll k = -1LL;
  bool can = true;
  for(ll i = 0LL; i < tl;i++){
    ll n = t[i]-'a';
    if((int)v[n].size()==0) {
      can=false;
      break;
    }
    if(upper_bound(v[n].begin(),v[n].end(),k)==v[n].end()){
      cnt++;
      k=v[n][0];
    }
    else k=*upper_bound(v[n].begin(),v[n].end(),k);
  }
  if(!can) cout<<-1<<endl;
  if(can)cout<<sl*cnt+k+1LL<<endl;
}