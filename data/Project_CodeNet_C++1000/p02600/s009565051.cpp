#include<bits/stdc++.h>
using namespace std;

int main () {
  int a, ans;
  cin >> a;
  a = a/100;
  
  if (a==4 || a==5) ans = 8;
  if (a==6 || a==7) ans = 7;
  if (a==8 || a==9) ans = 6;
  if (a==10 || a==11) ans = 5;
  if (a==12 || a==13) ans = 4;
  if (a==14 || a==15) ans = 3;
  if (a==16 || a==17) ans = 2;
  if (a==18 || a==19) ans = 1;
  cout << ans << endl;
}