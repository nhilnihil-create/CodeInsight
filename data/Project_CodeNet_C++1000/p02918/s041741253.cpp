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
  ll n, k;
  string s;
  cin >> n >> k >> s;
  char c = s[0];
  ll ans = 0, now = 0;
  rep2(i, 1, n) {
    if(s[i] == c)
      now++;
    else {
      ans += now;
      now = 0;
      c = s[i];
    }
  }
  ans += now;
  ans += k * 2;
  cout << min(ans, n - 1) << endl;
}