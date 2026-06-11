#include <bits/stdc++.h>
using namespace std;

int main(){
  double W, H, x, y;
  cin >> W >> H >> x >> y;
  
  double S = 0;
  S = W * H / 2;
  
  if(x == W/2 && y == H/2){
    printf("%lf %d", S, 1);
  }
  else{
    printf("%lf %d", S, 0);
  }
}