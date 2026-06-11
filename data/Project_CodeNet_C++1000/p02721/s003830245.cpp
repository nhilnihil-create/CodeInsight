/**
 *     author: qodjf
 *     created: 04.21.2020 00:39:18
 */
#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define mst(x, a) memset(x, a, sizeof(x))

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
  int N, K, C;
  cin >> N >> K >> C;
  string s;
  cin >> s;
  vector<int> dpleft(N + C + 10, 0), dpright(N + C + 10, 0);
  for (int i = 0; i < N; i++) {
    if (s[i] == 'x') {
      dpleft[i + C + 1] = dpleft[i + C];
    } else {
      dpleft[i + C + 1] = max(dpleft[i + C], 1 + dpleft[i]);
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    if (s[i] == 'x') {
      dpright[i] = dpright[i + 1];
    } else {
      dpright[i] = max(dpright[i + 1], 1 + dpright[i + C + 1]);
    }
  }
  dbg(dpleft, dpright);

  vector<bool> ans(N, true);
  if (C == 0) {
    for (int i = 0; i < N; i++) {
      if (dpleft[i] + dpright[i + 1] >= K) {
        ans[i] = false;
      }
    }
  } else {
    int rightmost = 0;
    for (int rb = 1; rb <= N + C; rb++) {
      if (dpleft[rb] + dpright[rb] >= K) {
        for (int j = max(rb - C, rightmost); j < min(N, rb); j++) {
          ans[j] = false;
        }
        rightmost = rb;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    if (s[i] == 'o' && ans[i]) {
      cout << i + 1 << endl;
    }
  }
}
