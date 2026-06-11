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
#include <tuple>
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
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> a(Q), b(Q), c(Q), d(Q);
  for (int i = 0; i < Q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<int> comb(M - 1 + N);
  for (int i = 0; i < N; i++) {
    comb[i] = 1;
  }
  sort(comb.begin(), comb.end());
  int mx = 0;
  int left = 1;
  do {
    vector<int> A;
    int tmp = 0;
    for (int i = 0; i < M - 1 + N; i++) {
      if (comb[i] == 1) A.push_back(left);
      if (comb[i] == 0) left++;
    }
    for (int i = 0; i < Q; i++) {
      if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
        tmp += d[i];
      }
    }
    mx = max(tmp, mx);
  } while (next_permutation(comb.begin(), comb.end()));
  cout << mx << endl;
  return 0;
}