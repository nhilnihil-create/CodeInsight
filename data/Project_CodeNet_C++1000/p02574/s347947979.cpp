#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back
#define rep(a, b, i) for(int i = a; i < b; i++)
#define repi(a, b, i) for(int i = a; i > b; i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define __ ios_base::sync_with_stdio(cin.tie(0) && 0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef double ld;

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

const ld pi = 3.141592653589793;
const ll inf = 1e18 + 5;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
const int mxn = 1e5 + 5;
const int mx = 1000;

int a[(int)1e6 + 1];
int lsb[(int)1e6 + 1];
set<int> s;
int main() {
  __;

  int n; cin >> n;
  int maxi = INT_MIN;
  rep(0, n, i) cin >> a[i], maxi = max(a[i], maxi);

  bool pw = 1, sw = 0;

  int gcdw = a[0];
  rep(1, n, i) {
    gcdw = __gcd(a[i], gcdw);
    if(gcdw == 1) break;
  }
  sw = (gcdw == 1);

  for(int i = 2; i <= maxi; i++) {
    if(lsb[i] == 0) {
      for(int j = i; j <= maxi; j += i) { lsb[j] = i; }
    }
  }
  

  for(int i = 0; i < n && pw; i++) {
    int temp = a[i];
    while(temp > 1) {
      int div = lsb[temp];
      if(s.count(div)) { pw = 0; break; }
      s.insert(div);
      while(temp > 1 && temp % div == 0) { temp /= div; }
    }
  }

  if(pw) cout << "pairwise coprime\n";
  else if(sw) cout << "setwise coprime\n";
  else cout << "not coprime\n";

  return 0;
}
