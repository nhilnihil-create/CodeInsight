#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

int main() {
  ll N,D,A;
  cin>>N>>D>>A;
  vector<vector<ll>> v(N,vector<ll>(2));
  for(ll i = 0LL; i < N; i++){
    ll X,H;
    cin>>X>>H;
    H=((H-1)/A) + 1;
    v[i][0]=X;
    v[i][1]=H;
  }
  sort(v.begin(),v.end());
  ll ans = 0LL;
  vector<ll> dam(N+1,0LL);
  ll d = 0LL;
  for(ll i = 0LL; i < N; i++) {
    if(i!=0) d=d+dam[i];
    if(v[i][1]<=d)continue;
    v[i][1]-=d;
    vector<ll> s = {v[i][0]+2LL*D,INF};
    auto ite = upper_bound(v.begin(),v.end(),s);
    ans+=v[i][1];
    dam[i]+=v[i][1];
    d+=v[i][1];
    dam[(int)(ite-v.begin())]-=v[i][1];
  }
  cout<<ans<<endl;
}