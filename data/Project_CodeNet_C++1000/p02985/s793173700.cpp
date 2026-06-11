#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

ll INF = 1e9;
ll MOD = 1e9+7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  vector<vector<int> > E(N, vector<int>());
  REP(i, N-1){
    int a, b; cin >> a >> b; a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  vector<ll> dist(N, INF);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  ll ans = K%MOD;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    ll cnt = 0;
    ll dep = 1;
    for(int i : E[cur]){
      if(dist[i] != INF) continue;
      cnt++;
      dist[i] = dist[cur]+1;
      dep = min(dist[i], 2LL);
      q.push(i);
    }
    for(ll i = 0; i < cnt; i++){
      ans = (ans*(K-dep-i))%MOD;
      if(K-dep-i <= 0){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
}
