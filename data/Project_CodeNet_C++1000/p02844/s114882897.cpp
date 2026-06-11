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

void move_keta(vector<int>& keta) {
  if (keta[2] == 9) {
    if (keta[1] == 9) {
      keta[0]++;
      keta[1] = 0;
      keta[2] = 0;
    } else {
      keta[1]++;
      keta[2] = 0;
    }
  } else {
    keta[2]++;
  }
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  vector<int> keta = {0, 0, 0};
  int hyaku, zyuu, iti;

  for (int pin = 0; pin < 1000; pin++) {
    hyaku = zyuu = iti = -1;
    for (int i = 0; i < N; i++) {
      if (S[i] - '0' == keta[0]) {
        hyaku = i;
        break;
      }
    }
    if (hyaku == -1) {
      move_keta(keta);
      continue;
    }
    for (int i = hyaku + 1; i < N; i++) {
      if (S[i] - '0' == keta[1]) {
        zyuu = i;
        break;
      }
    }
    if (zyuu == -1) {
      move_keta(keta);
      continue;
    }
    for (int i = zyuu + 1; i < N; i++) {
      if (S[i] - '0' == keta[2]) {
        iti = i;
        break;
      }
    }
    if (iti == -1) {
      move_keta(keta);
      continue;
    }
    ans++;
    move_keta(keta);
  }
  cout << ans << endl;
  return 0;
}