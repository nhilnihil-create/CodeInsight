#include <iostream>
#include <cmath>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  const double pi = 3.141592653589793;
  double a,b,h,m,ans,kaku;
  cin >> a >> b >> h >> m;
  
  kaku = (m/60)*360 - ((h*60+m)/720)*360;
  kaku = kaku / 180 * pi;
  
  ans = a*a + b*b - 2*a*b*cos(kaku);
  ans = sqrt(ans);
  
  printf("%0.20f", ans);
  
  return 0;
}
