#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  ll ans = 0;
  int ce, co;
  ce = w / 2;
  co = w / 2;
  if(w % 2 != 0) ++ce;
  if (h == 1 || w == 1) {
    cout << 1 << endl;
    return 0;
  }
  for(int i = 1; i<=h; ++i){
    if(i % 2 == 0) ans += co;
    else ans += ce;
  } 
  cout << ans << endl;
  return 0;
}