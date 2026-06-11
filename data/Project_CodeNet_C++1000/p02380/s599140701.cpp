#include <iostream>
#include <cmath>
#include <cstdio>
constexpr double PI = 3.14159265359;
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  double a, b, C;
  cin >> a; cin >> b; cin >> C;
  double h = b * sin(PI * C / 180);
  double S = 0.5 * a * h;
  double hoge = a - b * cos(C * PI / 180);
  double L = a + b + sqrt(h * h + hoge * hoge);
  printf("%1.6f\n" , S);
  printf("%1.6f\n" , L);
  printf("%1.6f\n" , h);
  return 0;
}