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

vector<P> ans;
ll n, k;

void f(ll r) {
  rep2(i, 1, n - 1) rep2(j, i + 1, n) {
    if(r == 0) return;
    ans.push_back({i, j});
    r--;
  }
}

int main() {
  cin >> n >> k;
  ll mx = (n - 1) * (n - 2) / 2;
  if(mx < k) {
    cout << -1 << endl;
    return 0;
  }
  rep(i, n - 1) ans.push_back({0, i + 1});
  ll r = mx - k;
  f(r);
  cout << ans.size() << '\n';
  for(auto p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}