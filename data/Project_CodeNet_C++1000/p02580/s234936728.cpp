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
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


typedef long long ll; 
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
 
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define S second
#define F first
#define PI 3.14159265358979323846

ll sqr(ll n) {
    return n*n;
}

ll binpow(ll a, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 != 0) return (binpow(a, n-1)*a); else {
        ll b = binpow(a, n/2);
        return (b*b);
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> r(h), c(w), R, C;
    set<pii> v;

    int x, y;
    int mxr = 0, mxc = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        r[x]++; c[y]++;
        mxr = max(mxr, r[x]);
        mxc = max(mxc, c[y]);
        v.insert({x, y});
    }

    for (int i = 0; i < h; i++) 
        if (mxr == r[i]) R.pb(i);
    for (int i = 0; i < w; i++)
        if (mxc == c[i]) C.pb(i);

    bool ok = false;
    for (int i : R) {
        for (int j : C) {
            if (!v.count({i, j})) {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }

    if (ok) cout << mxr + mxc << endl; else cout << mxr + mxc - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}