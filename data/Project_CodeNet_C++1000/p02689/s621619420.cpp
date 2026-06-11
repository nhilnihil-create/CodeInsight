#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
10^5全部みれる？
グループの中で1つとか
*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, M; cin>>N >> M;
  vector<ll> H(N+1, 0);
  for(ll i=1; i<=N; i++) cin>>H[i];
  vector<vector<ll>> G(N+1, vector<ll>(0,0));
  for(ll i=1; i<=M; i++){
    ll a,b; cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll ans = 0;
  for(ll i=1; i<=N; i++){
    ll tmp = H[i];
    ll gsz = G[i].size();
    if (gsz == 0)
      ans++;
    for(ll j=0; j<gsz; j++){
      if (H[G[i][j]] >= tmp)
        break;
      if (j == gsz - 1)
        ans++;
    }
  }
  cout<<ans<<endl;
}
