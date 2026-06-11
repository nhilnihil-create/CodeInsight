#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d,e; 
  cin >> a>>b>>c>>d>>e;
  int ans = 0; 
  if (a == 0) ans=1;
  if (b == 0) ans=2;
  if (c == 0) ans=3;
  if (d == 0) ans=4;
  if (e == 0) ans=5;
  cout << ans << endl;
  return 0;
 }