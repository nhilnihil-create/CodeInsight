#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> p(n), c(n);
  for (int i = 0; i < n; ++i) cin >> p[i], p[i]--;
  for (int i = 0; i < n; ++i) cin >> c[i];
  ll ans = LLONG_MIN;
  for (int i = 0; i < n; ++i) {
    int u = i, len = 0;
    ll sum = 0;
    while (true) {
      len++;
      u = p[u];
      sum += c[u];
      if (u == i) break;
    }
    u = i;
    int cur = 0;
    ll v = 0;
    while (true) {
      u = p[u];
      v += c[u];
      cur++;
      if (cur > k) break;
      ll x = (k - cur) / len;
      ans = max(ans, v + max(0LL, sum) * x); 
      if (u == i) break;
    }
  }
  cout << ans << '\n';
}