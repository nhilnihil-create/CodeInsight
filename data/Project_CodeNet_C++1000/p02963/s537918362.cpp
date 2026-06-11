#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  ll s; cin >> s;
  ll x1, y1, x2, y2, x3, y3;
  x1 = 1e9;
  x2 = 1;
  if(s % x1 == 0) y2 = s / x1;
  else y2 = s / x1 + 1;
  y1 = x1 * y2 - s;
  cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  //cout << abs(x1 * y2 - x2 * y1) << endl;
  return 0;
}
