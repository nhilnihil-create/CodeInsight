#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  int ans = 0;
  if(x <= 3) ans += (4-x) *100000;
  if(y <= 3) ans += (4-y) *100000;
  if(x == 1 && y == 1) ans += 400000;
  cout << ans << endl;
}