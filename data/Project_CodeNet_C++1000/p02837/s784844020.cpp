#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'


template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char c) {
  return string(1,c);
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
  for (int i = int(N)-1; i >= 0; --i) {
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
 
#ifdef COMPETITIVE_PROGRAMMING_LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) if(0){}
#endif

 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  vector<vector<array<int,2>>> A(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int  j = 0; j < k; ++j) {
      int x,y;
      cin >> x >> y;
      --x;
      A[i].push_back({x,y});
    }
  }

  int liar[15] = {};
  int ans = 0;
  for (int state = 0; state < (1 << n); ++state) {
    if (__builtin_popcount(state) <= ans) continue;
    // 1's represents people who are telling truth
    memset(liar, 0, sizeof(liar));

    for (int i = 0; i < n; ++i) {
      if (state >> i & 1) {
        for (int j = 0; j < A[i].size(); ++j) {
          if (A[i][j][1] == 0) liar[A[i][j][0]] = 1;
        }
      } else {
        liar[i] = true;
      }
    }
    bool good = true;
    for (int i = 0; i < n; ++i) {
      if (state >> i & 1) {
        if (liar[i]) {
          good = false;
          break;
        }

        for (int j = 0; j < A[i].size(); ++j) {
          if (liar[A[i][j][0]] != 1-A[i][j][1]) {
            good = false;
            break;
          }
        }
        if (!good) break;
      } else if (!liar[i]) {
//        good = false;
      }
    }
    if (good) {
      dbg(bitset<3>(state), vector<int>(liar,liar+3), A);
      ans = __builtin_popcount(state);
    }
  }
  
  cout << ans << endl;

}
