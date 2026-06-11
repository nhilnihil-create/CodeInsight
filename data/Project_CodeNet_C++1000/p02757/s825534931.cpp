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
  ll N,P;
  string S;
  cin>>N>>P>>S;
  if(P==2||P==5){
    reverse(S.begin(),S.end());
    map<ll,bool> m;
    rep(i,N) {
      int t = S[i] - '0';
      if(t%P==0) m[i] = true;
    }
    ll ans = 0;
    for(auto x:m) ans += N-x.first;
    cout<<ans<<endl;
  }
  else{
    reverse(S.begin(),S.end());
    vector<ll> MOD(N+1,0);
    ll B = 1LL;
    rep(i,N){
      ll t = S[i] - '0';
      MOD[i+1] = (MOD[i] + t*B)%P;
      B = (B*10)%P;
    }
    map<ll,ll> m;
    rep(i,N+1){
      m[MOD[i]]++;
    }
    ll ans = 0;
    for(auto x:m) ans += x.second*(x.second-1)/2;
    cout<<ans<<endl;
  }
}