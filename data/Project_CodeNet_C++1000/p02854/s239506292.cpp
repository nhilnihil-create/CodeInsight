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
  vl sum(n + 1, 0);
  rep(i, n) {
    ll a;
    cin >> a;
    sum[i + 1] = sum[i] + a;
  }
  ll ans = 1e18;
  rep2(i, 1, n) {
    ll x = sum[i];
    ll y = sum[n] - sum[i];
    ans = min(ans, abs(x - y));
  }
  cout << ans << endl;
}