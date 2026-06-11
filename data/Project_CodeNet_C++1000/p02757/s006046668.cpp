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
  int n, p; cin >> n >> p;
  string s; cin >> s;
  v1i v(n+1, 0), u(p-1, 1);
  rep(i, p-2){
    u[i+1] = u[i]*10;
    u[i+1] %= p;
  }
  rrep(i, n){
    v[i] = v[i+1] + u[(n-i-1)%(p-1)]*(s[i]-'0');
    v[i] %= p;
  }
  map<int, lint> m;
  rep(i, n+1) m[v[i]]++;
  lint a = 0;
  rep(i, p) a += m[i] * (m[i]-1) / 2;
  if(p == 2){
    a = 0;
    rep(i, n) if((s[i] - '0') % 2 == 0) a += i+1;
  }
  else if(p == 5){
    a = 0;
    rep(i, n) if((s[i] - '0') % 5 == 0) a += i+1;
  }
  cout << a << "\n";
  return 0;
}