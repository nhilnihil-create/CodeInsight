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

int main(){
  int n, t, a = 0; scanf("%d %d", &n, &t);
  vector<pii> v(n); rep(i, n) scanf("%d %d", &v[i].fi, &v[i].se);
  v2i dp1(n, v1i(t, 0)), dp2(n, v1i(t, 0));
  rep(i, n-1){
    rep(j, t-1){
      if(j < v[i].fi) dp1[i+1][j] = dp1[i][j];
      else dp1[i+1][j] = max(dp1[i][j], dp1[i][j-v[i].fi]+v[i].se);
    }
  }
  rrep(i, n-1){
    rep(j, t-1){
      if(j < v[i+1].fi) dp2[i][j] = dp2[i+1][j];
      else dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j-v[i+1].fi]+v[i+1].se);
    }
  }
  rep(i, n) rep(j, t) a = max(a, dp1[i][j]+dp2[i][t-j-1]+v[i].se);
  printf("%d\n", a);
  return 0;
}