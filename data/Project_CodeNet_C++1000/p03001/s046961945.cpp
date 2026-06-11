#include <iostream>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  int p;
  if ((double)x == w/2.0 && (double)y == h/2.0) p = 1;
  else p = 0;
  cout << (double)w * (double)h / 2.0 << ' ' << p << endl;
  
  return 0;
}