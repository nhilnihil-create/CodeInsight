#include<bits/stdc++.h>
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
  int n; cin >> n;
  bool b = 0;
  v1li v(n+1), u(n+1, 1); rep(i, n+1) cin >> v[i];
  lint a = 0, tmp = 0, tt = 0;
  rep(i, n+1){
    if(u[i] < v[i]){
      b = 1; break;
    }
    if(i < n){
      u[i+1] = (u[i] - v[i])*2;
      if(u[i+1] > 1e15) u[i+1] = 1e15;
    }
  }
  rrep(i, n+1){
    tt += v[i];
    tmp = min(tt, u[i]);
    a += tmp;
    tt = tmp;
  }
  if(n == 0) a = v[0];
  if(b) a = -1;
  cout << a << "\n";
  return 0;
}
