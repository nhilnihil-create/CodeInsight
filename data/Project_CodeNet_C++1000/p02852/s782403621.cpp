#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
#define fi first
#define se second
using namespace std;
using lint = long long;
using uint = unsigned int;
using ulint = unsigned long long;
using ldouble = long double;
using pii = pair<int, int>;
using pli = pair<lint, lint>;
using pdd = pair<double, double>;
using pld = pair<ldouble, ldouble>;
using v1i = vector<int>;
using v1li = vector<lint>;
using v2i = vector<vector<int>>;
using v2li = vector<vector<lint>>;
using v3i = vector<vector<vector<int>>>;
using v3li = vector<vector<vector<lint>>>;
using v1b = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<vector<vector<bool>>>;
using v1c = vector<char>;
using v2c = vector<vector<char>>;
using v3c = vector<vector<vector<char>>>;
constexpr lint mod1 = 1e9+7;
constexpr lint mod2 = 998244353;

int main() {
  int n, m, t, u, w;
  string s;
  cin >> n >> m >> s;
  v1i v = {0}; t = n;
  rep(i, n) if(s[i+1] == '0') v.push_back(i+1);
  stack<int> c; u = v.size()-1;
  while(t > 0){
    w = lower_bound(v.begin(), v.end(), t - m) - v.begin();
    if(w == u) break;
    else{
      c.push(v[u] - v[w]);
      u = w;
      t = v[u];
    }
  }
  if(t > 0) cout << -1 << "\n";
  else {
    while(!c.empty()){
      cout << c.top();
      c.pop();
      if(c.empty()) cout << "\n";
      else cout << " ";
    }
  }
  return 0;
}