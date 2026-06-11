#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll M = 1e9+7;  // 9..
const ll INF = 1e9+7;

ll n, m, done_max, ans[110000];;
vector<P> edge[110000];
ll done[110000];

void bfs(ll s) {
  queue<P> q;
  q.push(P(s, 0));
  while (q.size()) {
    P p = q.front();
    ll u = p.first;
    ll pre_color = p.second;
    q.pop();
    done[u] = true;
    ll color = 0;
    for (P p: edge[u]) {
      ll v = p.first;
      ll id = p.second;
      if (done[v]) continue;
      color++;
      if (color == pre_color) color++;
      ans[id] = color;
      done_max = max(done_max, color);
      q.push(P(v, color));
    }
  }
}

int main() {
  cin >> n;

  for (ll i = 0; i < n-1; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    edge[a].push_back(P(b, i));
    edge[b].push_back(P(a, i));
  }
  
  bfs(0);
  
  cout << done_max << endl;
  for (ll i = 0; i < n-1; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}