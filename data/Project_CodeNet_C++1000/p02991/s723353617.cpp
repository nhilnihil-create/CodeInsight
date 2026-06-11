#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;
const int MAXN = 100000;
vector<int> to[MAXN];


int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
  }
  int s, t;
  cin >> s >> t;
  s--; t--;

  vector<vector<int>> dist(MAXN, vector<int>(3, INF));
  dist[s][0] = 0;
  queue<P> q;
  q.emplace(s, 0);
  while(!q.empty()) {
    int v = q.front().first;
    int l = q.front().second;
    q.pop();
    for (int u : to[v]) {
      int nc = (l + 1) % 3;
      if (dist[u][nc] != INF) continue;
      dist[u][nc] = dist[v][l] + 1;
      q.emplace(u, nc);
    }
  }
  int ans = dist[t][0];
  if(ans == INF) ans = -1;
  else ans /= 3;

  cout << ans << endl;
}