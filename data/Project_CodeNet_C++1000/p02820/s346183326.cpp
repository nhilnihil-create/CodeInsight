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

ll n, k;
string hand = "rsp";
map<char, ll> score;
ll dp[100001][3];

ll Score(char t, char m) {
  if (t == m) {
    return 0;
  }
  if (t == 'r' && m == 's' ||
      t == 's' && m == 'p' ||
      t == 'p' && m == 'r') {
    return score[t];
  }
  return 0;
}

ll solve(const string& t) {
  dbg(t);
  rep(i, 3) dp[0][i] = 0;
  rep(i, t.size()) {
    rep(j, 3) {
      ll d = 0;
      rep(k, 3) {
        if (k != j) {
          d = max(d, dp[i][k]);
        }
      }
      dp[i + 1][j] = d + Score(hand[j], t[i]);
      dbg(i, j, hand[j], t[i], dp[i + 1][j]);
    }
  }
  ll ret = 0;
  rep(i, 3) ret = max(ret, dp[t.size()][i]);
  dbg(ret);
  return ret;
}

int main() {
  cin >> n >> k;
  rep(i, 3) cin >> score[hand[i]];
  in(string, t);
  vector<string> ts(k);
  rep(i, t.size()) {
    ts[i % k] += t[i];
  }
  ll ans = 0;
  rep(i, k) {
    ans += solve(ts[i]);
  }
  out(ans);
}
