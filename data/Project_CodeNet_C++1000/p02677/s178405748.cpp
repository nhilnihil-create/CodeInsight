#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  
  int a, b, h, m;
  
  cin >> a >> b >> h >> m;

  double hz = M_PI * ( 360.0 * ( h * 60 + m ) / 720 ) / 180.0;
  
  double hx = cos( hz ) * a;
  double hy = sin( hz ) * a;
  
  double mz = M_PI * ( 360.0 * m / 60 ) / 180.0;

  double mx = cos( mz ) * b;
  double my = sin( mz ) * b;
  
  double X = hx - mx;
  double Y = hy - my;
  
  printf("%.10f\n", sqrt( X * X + Y * Y ) );
  
  return 0;
}
