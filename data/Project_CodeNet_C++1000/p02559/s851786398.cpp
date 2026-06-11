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
  fenwick_tree<ll> fw(N);
  rep(i,N){
    ll a;
    cin>>a;
    fw.add(i,a);
  }
  rep(i,Q){
    ll a,b,c;
    cin>>a>>b>>c;
    if(a==0) fw.add(b,c);
    else {
      cout<<fw.sum(b,c)<<endl;
    }
  }
}