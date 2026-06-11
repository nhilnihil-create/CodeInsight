#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  ll d = k - a;
  if(d < 0) {
    cout << a - k << " " << b << endl;
    return 0;
  } 
  else{
    if (d == 0) {
      cout << d << " " << b << endl;
    }else{
      ll e = b - d;
      if (e >= 0) cout << 0 << " " << e << endl;
      else cout << 0 << " " << 0 << endl;
    }
  }
  return 0;
}