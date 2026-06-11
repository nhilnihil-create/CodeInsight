/**
 *     author: qodjf
 *     created: 04.18.2020 01:24:46
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
const ll MOD = 998244353;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

ll mul(ll a, ll b) { return a * b % MOD; }

ll add(ll a, ll b) { return (a + b) % MOD; }

ll sub(ll a, ll b) { return (a - b + MOD) % MOD; }

ll my_pow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> cnt(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  ll ans = 1;
  if (a[0] != 0 || cnt[0] != 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < N; i++) {
    dbg(i, cnt[i]);
    ans = mul(ans, my_pow(cnt[i-1], cnt[i]));
  }
  cout << ans << endl;
}
