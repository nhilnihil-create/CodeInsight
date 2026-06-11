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
  int n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, n) cin >> a[i];
  rep(_, k) {
    vi s(n + 2, 0);
    rep(j, n) {
      ll l = max(0, j - a[j]);
      ll r = min(n, j + a[j] + 1);
      s[l + 1]++;
      s[r + 1]--;
    }
    bool ok = true;
    rep(j, n) {
      s[j + 1] += s[j];
      if(s[j + 1] < n) ok = false;
      a[j] = s[j + 1];
    }
    if(ok) break;
  }
  rep(i, n) cout << a[i] << (i == n - 1 ? '\n' : ' ');
}