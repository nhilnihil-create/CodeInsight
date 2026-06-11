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
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    cin >> s[i];
  }
  debug(s);
  vector<vector<int>> dp(H, vector<int>(W));
  int right = 0;
  int down = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i == 0 && j == 0) {
        if (s[0][0] == '#')
          dp[0][0] = 1;
        else
          dp[0][0] = 0;
      } else if (i == 0) {
        if (s[i][j - 1] == '.' && s[i][j] == '#')
          right = dp[i][j - 1] + 1;
        else
          right = dp[i][j - 1];
        dp[i][j] = right;
      } else if (j == 0) {
        if (s[i - 1][j] == '.' && s[i][j] == '#')
          down = dp[i - 1][j] + 1;
        else
          down = dp[i - 1][j];
        dp[i][j] = down;
      } else {
        if (s[i][j - 1] == '.' && s[i][j] == '#')
          right = dp[i][j - 1] + 1;
        else
          right = dp[i][j - 1];
        if (s[i - 1][j] == '.' && s[i][j] == '#')
          down = dp[i - 1][j] + 1;
        else
          down = dp[i - 1][j];
        dp[i][j] = min(right, down);
      }
    }
  }
  debug(dp);
  cout << dp[H - 1][W - 1] << endl;
  return 0;
}