#include <bits/stdc++.h>
using namespace std;

int main () {
  double w,h,x,y;
  cin >> w >> h >> x >> y;
  int a=0;
  if(x==w/2 && y==h/2) a=1;
  cout << w*h/2 << " " << a << endl;
  return 0;
}