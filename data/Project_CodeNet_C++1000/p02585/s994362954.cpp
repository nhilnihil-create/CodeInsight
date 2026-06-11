#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll INF = 1e12;
const ll MOD = 1000000000 + 7;
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
#define mii map<int, int>
#define mci map<char, int>
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
void Yes_No(bool f) {
  if (f)
    printf("Yes\n");
  else
    printf("No\n");
}
void YES_NO(bool f) {
  if (f)
    printf("YES\n");
  else
    printf("NO\n");
}

template <typename T>
void deb1(T x) {
  cout << "debug: " << x << "\n";
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

void solve(void) {
  int n, k;
  cin >> n >> k;
  vi p(n), c(n);
  rep(i, n) cin >> p[i], p[i]--;
  rep(i, n) cin >> c[i];
  vi f(n, -1);
  int cta = 0;
  rep(i, n) {
    if (f[i] != -1) continue;
    set<int> st;
    ll nx = p[i];
    st.insert(i), f[i] = cta;
    while (st.find(nx) == st.end()) f[nx] = cta, nx = p[nx];
    ++cta;
  }
  map<int, ll> mp;
  rep(i, n) mp[f[i]] += c[i];
  cta = 0;
  ll ans = -INF;
  rep(i, n) {
    int sz = count(all(f), f[i]);
    if (sz == 0) break;
    ll num = 0;
    ll fund = mp[f[i]];
    int x;
    x = i;
    if (fund < 0)
      rep(j, min(k, sz)) num += c[p[x]], x = p[x], chmax(ans, num);
    else {
      int a = k / sz;
      int b = k - a * sz;
      rep(j, sz) {
        num += c[p[x]], x = p[x];
        if (j < b)
          chmax(ans, a * fund + num);
        else
          chmax(ans, (a - 1) * fund + num);
      }
    }
  }
  out(ans);
}

int main(void) { solve(); }