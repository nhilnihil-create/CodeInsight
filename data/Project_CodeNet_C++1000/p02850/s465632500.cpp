#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;

int main(){
  int N; cin >> N;
  vector<vector<pii>> G(N);
  rep(i,N-1){
    int a, b; cin >> a >> b;
    --a, --b;
    G[a].push_back({b,i});
    G[b].push_back({a,i});
  }
  int c_max = 0;
  rep(i,N) chmax(c_max, (int)G[i].size());
  cout << c_max << endl;
 
  queue<pii> q;
  q.push({0,-1});
  vector<int> ans(N-1,-1);
  bool passed[N] = {};
  passed[0] = true;
  
  while(!q.empty()){
    auto p = q.front(); q.pop();
    int v = p.first, c = p.second;
    int color = (c==1)? 2 : 1;
    for (auto e : G[v]){
      if (passed[e.first]) continue;

      passed[e.first] = true;
      q.push({e.first, color});
      ans[e.second] = color;
      color++;
      if (color==c) color++;
    }
  }
  rep(i,N-1) cout << ans[i] << endl;
  
  
  // cout << fixed << setprecision(10);
  
  return 0;
}
