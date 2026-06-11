#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  cin >> A;
  sort(A.begin(), A.end());
  int mx = A.back();
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    if (mp.count(A[i]))
      mp[A[i]]++;
    else
      mp[A[i]] = 1;
  }
  vector<int> v(mx + 1);
  for (auto m : mp) {
    if (m.second > 1) {
      for (int j = m.first; j <= mx; j += m.first) {
        v[j]++;
      }
    }
  }
  int64 ans = 0;
  for (int i = 0; i < N; i++) {
    if (v[A[i]] == 0) {
      ans++;
      for (int j = A[i]; j <= mx; j += A[i]) {
        v[j]++;
      }
      debug(A[i], v);
    }
  }
  cout << ans << endl;
  return 0;
}