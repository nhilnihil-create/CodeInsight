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
  ll n, sum = 0;
  cin >> n;
  vl a(n), b(n, 0);
  rep(i, n) {
    cin >> a[i];
    b[0] += a[i];
    if(i % 2) b[0] -= 2 * a[i];
  }
  rep(i, n - 1) b[i + 1] = 2 * a[i] - b[i];
  rep(i, n) cout << b[i] << '\n';
}