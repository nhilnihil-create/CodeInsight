#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  ll h,w;
  cin >> h >> w;
  ll a, b, c, ans;
  a = w * (h/2);
  b = ((w +1)/2);
  c =(h%2);
  ans = a + b * c;
  if ( h == 1 || w == 1) ans = 1;
  cout << ans;
}

