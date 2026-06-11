#include <bits/stdc++.h>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define INF (1 << 29)
#define LLINF (1LL << 60)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;

string to_string(string s) { return s; }
template <class S>
string to_string(unordered_set<S> s);
template <class S>
string to_string(set<S> s);
template <class S, class T>
string to_string(map<S, T> m);
template <class T>
string to_string(vector<T> v);

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

template <class S>
string to_string(unordered_set<S> s) {
  string ret = "{";
  for (S x : s) ret += to_string(x) + ",";
  return ret + "}";
}

template <class S>
string to_string(set<S> s) {
  string ret = "{";
  for (S x : s) ret += to_string(x) + ",";
  return ret + "}";
}

template <class S, class T>
string to_string(map<S, T> m) {
  string ret = "{";
  for (pair<S, T> x : m) ret += to_string(x) + ",";
  return ret + "}";
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

struct fastIO {
#ifdef _WIN32
  inline char getchar_unlocked() { return getchar(); }
  inline void putchar_unlocked(char c) { putchar(c); }
#endif
  template <class T>
  inline void read(T &x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c != '-' && c < '0' && '9' < c);
    bool minus = 0;
    if (c == '-') {
      minus = 1;
      c = getchar_unlocked();
    }
    x = 0;
    while ('0' <= c && c <= '9') {
      x *= 10;
      x += c - '0';
      c = getchar_unlocked();
    }
    if (minus) x = -x;
  }
  inline void read(string &x) {
    char c;
    x = "";
    do {
      c = getchar_unlocked();
      x += c;
    } while (c != ' ' && c != '\n');
  }
  template <class Head, class... Tail>
  inline void read(Head &head, Tail &... tail) {
    read(head);
    read(tail...);
  }
  template <class T>
  inline void write(T x) {
    char buf[32];
    int p = 0;
    if (x < 0) {
      x = -x;
      putchar_unlocked('-');
    }
    while (x > 0) {
      buf[p++] = (x % 10) + '0';
      x /= 10;
    }
    while (p) {
      putchar_unlocked(buf[--p]);
    }
  }
  inline void write(string x) {
    for (char c : x) putchar_unlocked(c);
  }
  template <class Head, class... Tail>
  inline void write(Head &head, Tail &... tail) {
    write(head);
    write(tail...);
  }
} io;

int main() {
  int M;
  io.read(M);
  ll sum = 0, ans = 0;
  FOR(i, M) {
    ll d, c;
    io.read(d, c);
    sum += d * c;
    ans += c;
  }
  ans--;
  while (sum >= 10) {
    ans += sum / 10;
    sum = sum % 10 + sum / 10;
  }
  io.write(ans);
  return 0;
}
