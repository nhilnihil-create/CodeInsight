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
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  map<ll,ll> m;
  rep(i,N) m[v[i]]++;
  ll cnt = 0;
  for(auto x:m) cnt++;
  if(cnt>=4||cnt==0) cout<<"No"<<endl;
  if(cnt==2){
    ll p = 0;
    vector<ll> q(2);
    bool ok = true;
    for(auto x:m){
      if(p==0){
        if(x.first != 0) ok = false;
        q[0] = x.second;
      }
      if(p==1){
        q[1] = x.second;
      }
      p++;
    }
    if(ok&&q[1]==(q[0]*2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  if(cnt==1) {
    ll t = 0;
    for(auto x:m) t = x.first;
    if(t==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  if(cnt==3){
    ll t = 0;
    vector<ll> q(3);
    ll p = 0;
    for(auto x:m) {
      t ^= x.first;
      q[p] = x.second;
      p++;
    }
    if(t==0&&q[0]==q[1]&&q[1]==q[2]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}