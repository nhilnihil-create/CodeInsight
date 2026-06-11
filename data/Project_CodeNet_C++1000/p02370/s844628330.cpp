#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(false)
#define pb push_back
#define pf pop_front
typedef long long ll;
typedef pair<int, int> pii;

const ll MAX_N = 10 * 1000 + 24;

int n, m;
int d[MAX_N];
vector<int> G[MAX_N], vec;
deque<int> dq;

int main() {
  FAST;
  cin>>n>>m;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin>>u>>v;
    G[u].pb(v);
    d[v]++;
  }
  for (int i = 0; i < n; i++) {
    if (d[i] == 0) {
      dq.pb(i);
      vec.pb(i);
    }
  }
  while (dq.size()) {
    for (int j = 0; j < G[dq[0]].size(); j++) {
      u = G[dq[0]][j];
      d[u]--;
      if (d[u] == 0) {
        dq.pb(u);
        vec.pb(u);
      }
    }
    dq.pf();
  }
  for (int i = 0; i < n; i++) {
    cout<<vec[i]<<"\n";
  }
}

