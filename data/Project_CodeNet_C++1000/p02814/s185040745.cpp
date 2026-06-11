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
  ll n, m;
  cin >> n >> m;
  vl a(n);
  rep(i, n) {
    cin >> a[i];
    a[i] /= 2;
  }
  ll lcm, k;
  rep(i, n) {
    ll nk = 0;
    ll b = a[i];
    while(b % 2 == 0) {
      b /= 2;
      nk++;
    }
    if(i == 0) {
      k = nk;
      lcm = a[i];
      continue;
    }
    if(k != nk) {
      cout << 0 << endl;
      return 0;
    }
    lcm = lcm / __gcd(lcm, a[i]) * a[i];
  }
  cout << (m / lcm + 1) / 2 << endl;
}