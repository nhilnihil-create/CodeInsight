#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  in(int, h, w);
  int H = h + 2, W = w + 2;

  vector<string> s(H);
  s[0] = s[H - 1] = string(W, '#');
  rep(i, h) {
    in(string, row);
    s[i + 1] = '#' + row + '#';
  }

  vector<vector<int>> left(H, vector<int>(W)), right = left, top = left,
                                               bottom = left;
  rep(r, H) {
    for (int c = 1; c < W - 1; ++c) {
      left[r][c] = (s[r][c - 1] == '#') ? 0 : left[r][c - 1] + 1;
      dbg(r, c, left[r][c]);
    }
    for (int c = W - 2; c > 0; --c) {
      right[r][c] = (s[r][c + 1] == '#') ? 0 : right[r][c + 1] + 1;
      dbg(r, c, right[r][c]);
    }
  }
  rep(c, W) {
    for (int r = 1; r < H - 1; ++r) {
      top[r][c] = (s[r - 1][c] == '#') ? 0 : top[r - 1][c] + 1;
      dbg(r, c, top[r][c]);
    }
    for (int r = H - 2; r > 0; --r) {
      dbg(r, c);
      bottom[r][c] = (s[r + 1][c] == '#') ? 0 : bottom[r + 1][c] + 1;
      dbg(r, c, bottom[r][c]);
    }
  }
  int ans = 0;
  rep(r, H) rep(c, W) if (s[r][c] == '.') {
    ans = max(ans, left[r][c] + right[r][c] + top[r][c] + bottom[r][c] + 1);
  }
  out(ans);
}
