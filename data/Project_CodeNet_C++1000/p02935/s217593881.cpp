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
  vl v(n);
  rep(i, n) cin >> v[i];
  sort(all(v));
  double ans = 0;
  rep(i, n) {
    double now = double(v[i]) * pow(0.5, n - i);
    if(i == 0) now *= 2;
    ans += now;
  };
  printf("%.10f\n", ans);
}