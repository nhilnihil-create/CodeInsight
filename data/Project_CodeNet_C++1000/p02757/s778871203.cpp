#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rrep(i, n) for(int i = n-1; i >= 0; --i)
using namespace std;
using lint = long long;
using v1i = vector<int>;

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