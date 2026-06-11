#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, y; cin >> x >> y;
  int ans = 0;
  if (x <= 3){
    ans += 300000 - 100000*(x-1);
  }
  if (y <= 3){
    ans += 300000 - 100000*(y-1);
  }
  if (x == 1 && y == 1) ans += 400000;
  cout << ans << endl;
}