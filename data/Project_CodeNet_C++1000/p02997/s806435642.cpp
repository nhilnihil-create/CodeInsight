#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  if ((n - 2) * (n - 1) / 2 < k) {
    puts("-1");
    return 0;
  }

  vector<pii> G;
  // create star graph
  for (int i = 1; i < n; i++){
    G.pb({1, i + 1});
  }
  int cnt = (n - 2) * (n - 1) / 2 - k;
  vector<pii> rec;
  for (int i = 2; i < n; i++){
    for (int j = i ; j < n; j++){
      rec.pb({i, j + 1});
    }
  }
  rep(i, cnt) G.pb(rec[i]);

  cout << sz(G) << endl;
  rep(i,sz(G)){
    cout << G[i].fi << " " << G[i].se << endl;
  }
  return 0;
}