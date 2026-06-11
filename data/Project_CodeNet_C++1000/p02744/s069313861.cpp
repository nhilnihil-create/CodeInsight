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

ll t(string s) {
  set<char> st;
  for(char c : s) st.insert(c);
  return st.size();
}

vs dfs(ll n) {
  if(n == 1) return {"a"};
  vs ss = dfs(n - 1);
  vs res;
  for(auto s : ss) {
    ll m = t(s) + 1;
    rep(i, m) res.push_back(s + char(i + 'a'));
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vs ans = dfs(n);
  for(auto v : ans) cout << v << '\n';
}