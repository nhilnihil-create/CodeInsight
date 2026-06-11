#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector< pair<int, int> > adj[n];
  
  for(int i = 0; i < n; i++) {
    int ix, nn; cin >> ix >> nn;
    for(int j = 0; j < nn; j++) {
      int v, c; cin >> v >> c;
      adj[ix].push_back(make_pair(c, v));
    }
  }

  int inf = 10000000;
  int ans[n];
  fill(ans, ans+n, inf);

  ans[0] = 0;
  int ix = 0, sd[n] = {1};
  while(true) {

    for(int i = 0; i < adj[ix].size(); i++) {
      int cost = ans[ix] + adj[ix][i].first;
      int k = adj[ix][i].second;

      if(cost < ans[k]) {
        ans[k] = cost;
        sd[k] = 0;
      }

    }

    sd[ix] = 1;
    ix = -1;
    for(int i = 0; i < n; i++) {
      if(sd[i] == 0 && (ix == -1 || ans[ix] > ans[i])) {
        ix = i;
      }
    }
    if(ix == -1) {
      break;
    }
  }

  for(int i = 0; i < n; i++) {
    cout << i << " " << ans[i] << endl;
  }
}