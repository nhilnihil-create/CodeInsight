#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, m, s, t;
  cin >> n >> m;
  vector<vl> g(n);
  vector<vl> d(n, vl(3, -1));
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }
  cin >> s >> t;
  s--;
  t--;
  queue<P> q;
  d[s][0] = 0;
  q.push({s, 0});
  while(!q.empty()) {
    ll i = q.front().first;
    ll k = q.front().second;
    ll nk = (k + 1) % 3;
    q.pop();
    for(auto v : g[i]) {
      if(d[v][nk] != -1) continue;
      d[v][nk] = d[i][k] + 1;
      q.push({v, nk});
    }
  }
  cout << (d[t][0] < 0 ? -1 : d[t][0] / 3) << endl;
}