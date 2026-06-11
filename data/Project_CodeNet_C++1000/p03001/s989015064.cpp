#include<bits/stdc++.h>
using namespace std;

int main(){
  double x,y,w,h;
  cin >> w >> h >> x >> y;
  cout << w*h/2 << " " << (x*2==w&&y*2==h?1:0) << endl;
  return 0;
}