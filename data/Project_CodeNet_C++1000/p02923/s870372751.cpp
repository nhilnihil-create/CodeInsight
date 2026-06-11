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
  ll n;
  cin >> n;
  vl h(n);
  rep(i, n) cin >> h[i];
  vl dp(n, 0);
  for(ll i = n - 2; i >= 0; i--)
    if(h[i] >= h[i + 1]) dp[i] = dp[i + 1] + 1;
  cout << *max_element(all(dp)) << endl;
}