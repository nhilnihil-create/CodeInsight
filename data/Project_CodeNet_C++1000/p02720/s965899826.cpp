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
  ll k;
  cin >> k;
  if(k <= 9) {
    cout << k << endl;
    return 0;
  }
  queue<ll> q;
  ll cnt = 9, ans;
  rep2(i, 1, 10) q.push(i);
  while(true) {
    ll x = q.front();
    q.pop();
    ll d = x % 10;
    if(d != 0) {
      ll m = x * 10 + d - 1;
      q.push(m);
      cnt++;
      ans = m;
      if(cnt == k) break;
    }
    ll m = x * 10 + d;
    q.push(m);
    cnt++;
    ans = m;
    if(cnt == k) break;
    if(d != 9) {
      ll m = x * 10 + d + 1;
      q.push(m);
      cnt++;
      ans = m;
      if(cnt == k) break;
    }
  }
  cout << ans << endl;
}