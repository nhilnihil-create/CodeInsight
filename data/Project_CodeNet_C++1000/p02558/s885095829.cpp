#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  ll N,Q;
  cin>>N>>Q;
  dsu d(N);
  rep(i,Q){
    ll t,u,v;
    cin>>t>>u>>v;
    if(t==0) d.merge(u,v);
    else{
      if(d.same(u,v)) cout<<1<<endl;
      else cout<<0<<endl;
    }
  }
}