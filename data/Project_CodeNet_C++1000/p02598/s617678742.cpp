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
  int f = 0, g = 1e9, h = (f+g)/2, n, k, d; cin >> n >> k;
  v1i v(n); rep(i, n){cin >> v[i]; v[i]--;}
  while(g - f > 0){
    int t = 0;
    rep(i, n) t += v[i] / (h+1);
    if(t <= k){
      d = h+1;
      g = h;
      h = (f+g)/2;
    }
    else{
      f = h+1;
      h = (f+g)/2;
    }
  }
  cout << d << endl;
}