#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

vector<int> z_algorighm(string s) {
  vector<int> z(s.size());
  z[0] = s.size();
  int i = 1, j = 0;
  while (i < s.size()) {
    while (i + j < s.size() && s[j] == s[i + j]) j++;
    z[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (k < j && k + z[k] < j) {
      z[i + k] = z[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return z;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;

  for (int l1 = 0; l1 < s.size() - 1; l1++) {
    auto z = z_algorighm(s.substr(l1));
    for (int i = 1; i < z.size(); i++) {
      chmax(ans, min(z[i], i));
    }
  }

  cout << ans << endl;

  return 0;
}
