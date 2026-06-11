#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15)

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> graph(n*3);
  ll a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--, b--;
    graph[a*3+0].emplace_back(b*3+1);
    graph[a*3+1].emplace_back(b*3+2);
    graph[a*3+2].emplace_back(b*3+0);
  }
  
  vector<ll> d(3*n, -3);
  queue<ll> que;
  ll s, t;
  cin >> s >> t;
  s--, t--;
  d[3*s] = 0;
  que.push(3*s);
  while(!que.empty()) {
    ll p = que.front(); que.pop();
    if (p == 3 * t) break;
    for (ll nx: graph[p]) {
      if (d[nx] == -3) {
        d[nx] = d[p] + 1;
        que.push(nx);
      }
    }
  }
  cout << d[3*t] / 3 << endl;
}
