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
  int N, M;
  int64 K;
  cin >> N >> M >> K;
  vector<int64> A(N), B(M);
  cin >> A >> B;
  vector<int64> sum_a(N + 1, 0), sum_b(M + 1, 0);
  for (int i = 1; i < N + 1; i++) {
    sum_a[i] = sum_a[i - 1] + A[i - 1];
  }
  for (int i = 1; i < M + 1; i++) {
    sum_b[i] = sum_b[i - 1] + B[i - 1];
  }
  debug(sum_a);
  debug(sum_b);
  int max_sassu = 0;
  for (int i = 0; i <= N; i++) {
    if (sum_a[i] > K) break;
    auto b_idx = upper_bound(sum_b.begin(), sum_b.end(), K - sum_a[i]);
    if (b_idx - sum_b.begin() == M + 1) {
      max_sassu = max(max_sassu, M + i);
      continue;
    }
    max_sassu = max(max_sassu, (int)(b_idx - sum_b.begin()) + i - 1);
  }
  cout << max_sassu << endl;
  return 0;
}