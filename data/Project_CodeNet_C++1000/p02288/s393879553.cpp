// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
template<typename T = int> T in() { T x; cin >> x; return x; }
template<typename T = int> T in(T &&x) { T z(forward<T>(x)); cin >> z; return z; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is; }
// clang-format on

int main() {
  int n = in();
  auto v = in(vector<int>(n));
  make_heap(all(v));
  rep(i, n) cout << ' ' << v[i];
  cout << endl;
}

