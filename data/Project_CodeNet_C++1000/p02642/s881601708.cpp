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
  ll n, ans = 0;
  cin >> n;
  vl a(n);
  vb ng(1e6 + 1, false);
  rep(i, n) cin >> a[i];
  sort(all(a));
  rep(i, n) {
    if(ng[a[i]]) continue;
    if(i == n - 1 || a[i] != a[i + 1]) ans++;
    for(ll k = a[i]; k <= 1e6; k += a[i]) ng[k] = true;
  }
  cout << ans << endl;
}