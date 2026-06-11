#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
#define fi first
#define se second
using namespace std;
using lint = long long;
using uint = unsigned int;
using ulint = unsigned long long;
using ldouble = long double;
using pii = pair<int, int>;
using pli = pair<lint, lint>;
using pdd = pair<double, double>;
using pld = pair<ldouble, ldouble>;
using v1i = vector<int>;
using v1li = vector<lint>;
using v2i = vector<vector<int>>;
using v2li = vector<vector<lint>>;
using v3i = vector<vector<vector<int>>>;
using v3li = vector<vector<vector<lint>>>;
using v1b = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<vector<vector<bool>>>;
using v1c = vector<char>;
using v2c = vector<vector<char>>;
using v3c = vector<vector<vector<char>>>;
constexpr lint mod1 = 1e9+7;
constexpr lint mod2 = 998244353;

int main() {
  lint n, d, a;
  cin >> n >> d >> a;
  vector<pli> v(n);
  v1li b(n+1), x(n); b[0] = 0;
  rep(i, n) cin >> v[i].fi >> v[i].se;
  sort(v.begin(), v.end());
  rep(i, n) x[i] = v[i].fi;
  rep(i, n){
    v[i].se -= a * (b[i]-b[lower_bound(x.begin(), x.end(), v[i].fi-2*d)-x.begin()]);
    b[i+1] = b[i];
    if(v[i].se > 0) b[i+1] += (v[i].se-1)/a + 1;
  }
  cout << b[n] << endl;
  return 0;
}