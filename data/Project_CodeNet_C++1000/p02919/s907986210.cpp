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
  rep(i,N) v[i]--;
  vector<ll> place(N);
  rep(i,N) place[v[i]] = i;
  set<ll> s;
  ll ans = 0;
  s.insert(-1);
  s.insert(N);
  for(ll i = N-1; i >= 0; i --){
    if(i==N-1){
      s.insert(place[i]);
      continue;
    }
    auto ite1 = s.insert(place[i]);
    auto ite = ite1.first;
    auto ite2 = ite;
    auto ite3 = ite;
    ite3++;
    auto ite5 = ite3;
    ite5++;
    ite2--;
    ll cnt = 0;
    if(ite2!=s.begin()){
      auto ite4 = ite2;
      ite4--;
      cnt += (*ite2-*ite4)*(*ite3-place[i]);
    }
    if(ite5!=s.end()){
      cnt += (*ite5-*ite3)*(place[i] - *ite2);
    }
    ans += cnt * (i+1);
  }
  cout<<ans<<endl;
}