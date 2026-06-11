/**
*    author: lucasfcm9
*    created: 28.08.20 16:01:11
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> g(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> g[i][j];
    }
  }
  int n;
  cin >> n;
  bool ok = false;
  vector<vector<int>> h(3, vector<int>(3));
  while (n--) {
    int b;
    cin >> b;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (g[i][j] == b) {
          h[i][j] = 1;
        }
      }
    }
  }
  int sd1 = 0, sd2 = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j && h[i][j] == 1) {
        sd1++;
      }
      if (i + j == 2 && h[i][j] == 1) {
        sd2++;
      }
    }
  }
  int sl = 0, sc = 0;
  for (int i = 0; i < 3; i++) {
    sl = 0, sc = 0;
    for (int j = 0; j < 3; j++) {
      if (h[i][j] == 1) {
        sl++;
      }
      if (h[j][i] == 1) {
        sc++;
      }
    }
    debug(sl, sc, sd1, sd2);
    if (sl == 3 || sc == 3 || sd1 == 3 || sd2 == 3) {
      ok = true;
      break;
    }
  }
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}
