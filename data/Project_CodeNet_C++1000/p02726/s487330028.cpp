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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> G[n];
  vector<vector<int>> dist(n,vector<int>(n,-1)); // dist[i][j]:iからjへの距離
  x--, y--;
  G[x].pb(y);
  G[y].pb(x);
  rep(i, n - 1) { 
    G[i].pb(i + 1);
    G[i + 1].pb(i);
  }
  rep(s,n) {
    dist[s][s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      int now = q.front();
      q.pop();
      for (auto nx : G[now]) {
        if (dist[s][nx] != -1) continue;
        dist[s][nx] = dist[s][now] + 1;
        q.push(nx);
      }
    }
  }
  vector<int> ans(n,0);
  rep(i, n) rep(j, n) ans[dist[i][j]]++;
  for (int i = 1; i < n; i++){
    cout << ans[i]/2 << endl;
  }
  return 0;
}