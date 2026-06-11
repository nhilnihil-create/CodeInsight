#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1001001001;


int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
  }

  int s, t;
  cin >> s >> t;
  --s; --t;

  vector<vector<int>> dist(n, vector<int>(3, INF));
  queue<P> q;
  q.emplace(s, 0);
  dist[s][0] = 0;

  while (!q.empty()) {
    int v, c;
    tie(v, c) = q.front(); q.pop();
    int ndist = dist[v][c] + 1;
    int nc = (c + 1) % 3;

    for (int u : to[v]) {
      if (ndist >= dist[u][nc]) continue;
      dist[u][nc] = ndist;
      q.emplace(u, nc);
    }
  }

  int ans = dist[t][0] != INF ? dist[t][0] / 3 : -1;

  cout << ans << endl;
}