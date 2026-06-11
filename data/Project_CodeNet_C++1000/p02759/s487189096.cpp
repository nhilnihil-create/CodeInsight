#include <bits/stdc++.h>
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename T> string to_string(T v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
template <typename T, typename U> string to_string(pair<T, U> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
void print_debug() { cerr << endl; }
template <typename T, typename... U> void print_debug(T t, U... u) { cerr << " " << to_string(t); print_debug(u...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", print_debug(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  cout << (n+1)/2;
}
