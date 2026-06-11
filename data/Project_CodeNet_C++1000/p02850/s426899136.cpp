#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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
  ll n;
  cin >> n;
  vector<vector<P>> g(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(P(b, i));
    g[b].push_back(P(a, i));
  }
  vl ans(n - 1, 0);
  vb seen(n, false);
  queue<P> q;
  q.push(P(0, 0));
  seen[0] = true;
  while(!q.empty()) {
    int i = q.front().first;
    int parent = q.front().second;
    q.pop();
    ll k = 1;
    for(auto v : g[i]) {
      if(seen[v.first]) continue;
      if(k == parent) k++;
      ans[v.second] = k;
      q.push(P(v.first, k));
      seen[v.first] = true;
      k++;
    }
  }
  cout << *max_element(all(ans)) << '\n';
  rep(i, n - 1) cout << ans[i] << '\n';
}