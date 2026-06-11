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
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    cin >> grid[i];
  }
  debug(grid);
  vector<vector<vector<int>>> dp(H, vector<vector<int>>(W, vector<int>(5)));
  for (int i = 0; i < W; i++) {
    if (grid[0][i] == '.') dp[0][i][0] = 1;
    int cnt = 0;
    for (int j = 1; j < H; j++) {
      if (grid[j][i] == '#')
        break;
      else
        cnt++;
    }
    dp[0][i][2] = cnt;
  }
  debug(dp);
  for (int i = 0; i < H; i++) {
    if (grid[i][0] == '.') dp[i][0][0] = 1;
    int cnt = 0;
    for (int j = 1; j < W; j++) {
      if (grid[i][j] == '#')
        break;
      else
        cnt++;
    }
    dp[i][0][4] = cnt;
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '.')
        dp[i][j][0] = 1;
      else
        dp[i][j][0] = 0;

      if (i > 0) {
        if (dp[i - 1][j][0] == 1) {
          dp[i][j][1] = dp[i - 1][j][1] + 1;
          dp[i][j][2] = dp[i - 1][j][2] - 1;
        } else {
          dp[i][j][1] = 0;
          if (i == H - 1)
            dp[i][j][2] = 0;
          else {
            int cnt = 0;
            for (int k = i + 1; k < H; k++) {
              if (grid[k][j] == '#')
                break;
              else
                cnt++;
            }
            dp[i][j][2] = cnt;
          }
        }
      }
      if (j > 0) {
        if (dp[i][j - 1][0] == 1) {
          dp[i][j][3] = dp[i][j - 1][3] + 1;
          dp[i][j][4] = dp[i][j - 1][4] - 1;
        } else {
          dp[i][j][3] = 0;
          if (j == W - 1)
            dp[i][j][4] = 0;
          else {
            int cnt = 0;
            for (int k = j + 1; k < W; k++) {
              if (grid[i][k] == '#')
                break;
              else
                cnt++;
            }
            dp[i][j][4] = cnt;
          }
        }
      }
    }
  }
  debug(dp);
  int mx = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#') continue;
      int sm =
          dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3] + dp[i][j][4];
      mx = max(mx, sm);
    }
  }
  cout << mx << endl;
  return 0;
}