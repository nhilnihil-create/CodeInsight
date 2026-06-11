#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = 0, y = 0;
  while (c > 0) {
    c -= b;
    x++;
  }
  while (a > 0) {
    a -= d;
    y++;
  }
  if (y >= x) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}