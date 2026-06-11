#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a;
  int64_t D,x,y,DS,xS,yS;
  a=0;
  cin >> N >> D;
  DS=D*D;
  for(int i=0; i<N; i++){
    cin >> x >> y;
    xS =x*x;
    yS= y*y;
    if (xS + yS <= DS)
      a++;
  }
  cout << a << endl;
}
