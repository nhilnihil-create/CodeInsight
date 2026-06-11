#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  multiset<ll,greater<ll>> all;
  rep(i,1LL<<N){
    ll t;
    cin>>t;
    all.insert(t);
  }
  multiset<ll,greater<ll>> now;
  now.insert(*all.begin());
  all.erase(all.begin());
  bool ok = true;
  while(now.size()!=1LL<<N){
    auto ite = all.begin();
    queue<ll> q;
    for(auto x:now){
      while(ite != all.end()&&x<=*ite){
        ite++;
      }
      if(ite==all.end()) {
        ok = false;
        break;
      }
      q.push(*ite);
      ite++;
    }
    if(!ok) break;
    while(!q.empty()){
      ll t = q.front();
      q.pop();
      all.erase(all.find(t));
      now.insert(t);
    }
  }
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}