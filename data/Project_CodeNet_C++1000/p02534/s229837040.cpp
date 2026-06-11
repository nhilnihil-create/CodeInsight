#include <bits/stdc++.h>
#ifdef _DEBUG
#include "_DEBUG.hpp"
#endif
#define int long long
using namespace std;
using P = pair<int, int>;
const int inf = 2e18;
const int mod = 1e9 + 7;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in : v) is >> in;
  return is;
}

template <class T>
vector<T> make_vec(size_t a) {
  return vector<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template <class T, class V>
typename enable_if<is_class<T>::value == 0>::type fill(T &t, const V &v) {
  t = v;
}

template <class T, class V>
typename enable_if<is_class<T>::value != 0>::type fill(T &t, const V &v) {
  for (auto &e : t) fill(e, v);
}

signed main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cout << "ACL";
  }
  cout << endl;

  return 0;
}