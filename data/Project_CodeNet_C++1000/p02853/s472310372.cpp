#include <bits/stdc++.h>
using namespace std;

int solve(int a){
  int res = 0;
  if(a == 1) res = 300000;
  if(a == 2) res = 200000;
  if(a == 3) res = 100000;
  
  return res;
}

int main() {
  int x, y;
  cin >> x >> y;
  
  int ans = solve(x) + solve(y);
  if(ans == 600000) ans += 400000;
  
  cout << ans << endl;
}