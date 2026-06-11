#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1e12

#define PB push_back
#define PF push_front
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vpi vector<pii>
#define vll vector<ll>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pr_d(x) cout << fixed << setprecision(15) << x << endl
#define ud(c, x) distance(c.begin(), upper_bound(all(c), x))
#define ld(c, x) distance(c.begin(), lower_bound(all(c), x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rep3(i, n) for (int i = (n - 1); i >= 0; --i)
#define rep4(i, a, b) for (int i = (a); i > (b); --i)
#define pb push_back
#define out(x) cout << x << "\n"
bool odd(int i) { return i % 2; }

#define all(v) v.begin(), v.end()
#define size(x) int(x.size())

int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
void Yes_NO(bool f) {
  if (f)
    printf("Yes\n");
  else
    printf("NO\n");
}

void deb_p(pii p) { printf("pair = %d %d\n", p.fi, p.se); }
void deb_i(int i) { printf("i = %d\n", i); }
void deb_v(vector<int> v) {
  printf("v = ");
  for (auto i : v) printf("%d ", i);
  printf("\n");
}
template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
//-------------------ここから回答する-----------------------

set<vi> st;
int ans = 0;

void f(vi v, int n, int m, int x) {
  if (x == n) {
    st.insert(v);
    return;
  }

  rep2(i, min(v[max(0, x - 1)], m), m) {
    v[x] = i;
    f(v, n, m, x + 1);
  }
}
int g(vi v, vi a, vi b, vi c, vi d) {
  int res = 0;
  rep(i, size(a)) if (v[b[i]] - v[a[i]] == c[i]) res += d[i];
  return res;
}

void solve(void) {
  int n, m, q;
  cin >> n >> m >> q;
  vi a(q), b(q), c(q), d(q);
  rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i], --a[i], --b[i];
  vi v;
  rep(i, n) v.pb(0);
  f(v, n, m, 0);

  for (auto& i : st) chmax(ans, g(i, a, b, c, d));
  cout << ans << endl;
}
int main(void) { solve(); }
