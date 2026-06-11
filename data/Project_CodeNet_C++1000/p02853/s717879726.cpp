#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int x,y,ans = 0;
  cin >> x >> y;
  if(x == 1) ans += 3e5;
  if(x == 2) ans += 2e5;
  if(x == 3) ans += 1e5;
  if(y == 1) ans += 3e5;
  if(y == 2) ans += 2e5;
  if(y == 3) ans += 1e5;
  if(x == 1 && y == 1) ans += 4e5;
  cout << ans << endl;
}