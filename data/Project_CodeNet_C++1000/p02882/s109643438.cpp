#include<bits/stdc++.h>
using namespace std;

double a, b, x;
double theta;
#define D 180 / M_PI
/*図形問題*/

int main(){
  cin >> a >> b >> x;
  double S = x / a;                //水と側面の接触面積
  if(S >= a * b / 2) theta = atan((2 * b - 2 * x / a / a) / a) * D;    //傾けたとき側面が台形
  else theta = atan(b*b/S/2) *  D;  // 側面が底面の辺を用いて構成される三角形<-2倍
  printf("%.8f\n", theta);
  return 0;

  
}
