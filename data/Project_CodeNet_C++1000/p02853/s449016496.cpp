#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
  int X, Y;
  cin >> X >> Y;
  vector<int> money = {300000, 200000, 100000};
  int ans = 0;
  if(X < 4) ans += money[X-1];
  if(Y < 4) ans += money[Y-1];
  if(X==1 && Y==1) ans += 400000;
  cout << ans << endl;
  return 0;
}