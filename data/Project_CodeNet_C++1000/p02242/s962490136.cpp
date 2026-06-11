#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define dpr(x) cerr<<#x<<": "<<x<<endl;
#define dprc(c) do{cerr<<#c<<":";for(auto&_i:(c)){cerr<<" "<<_i;}cerr<<endl;}while(0)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int INF = 1e9+7;
#define all(c) (c).begin(), (c).end()
#define tr(i,c) for(auto i=(c).begin();i!=(c).end();i++)
#define rtr(i,c) for(auto i=(c).rbegin();i!=(c).rend();i++)
#define rep(i,b) for(auto i=0;i<(b);i++)
#define pb push_back
#define sz(c) int((c).size())

int main(int argc, char **argv)
{
  int n;
  scanf("%d", &n);

  vector<vector<pii>> G(n, vector<pii>());
  for (int i = 0; i < n; i++) {
    int u, k, v, c;
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d %d", &v, &c);
      G[u].pb(pii(v, c));
    }
  }

  vi d(n, INF);
  vector<bool> visited(n, false);
  int vc = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q;

  d[0] = 0;
  visited[0] = true;
  vc = 1;
  q.push(pii(0, 0));
  
  while(!q.empty()) {
    pii p = q.top(); q.pop();
    int u = p.second;

    if (d[u] < p.first) continue;

    visited[u] = true;
    for (auto e:G[u]) {
      int v = e.first;
      int c = e.second;
      if (!visited[v] && (d[u] + c < d[v])) {
        d[v] = d[u] + c;
        q.push(pii(d[v], v));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d %d\n", i, d[i]);
  }

  return 0;
}